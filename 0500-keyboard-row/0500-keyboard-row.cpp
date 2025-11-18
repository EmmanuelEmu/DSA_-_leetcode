class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> row_sequence = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL", "zxcvbnmZXCVBNM"};
        map<char, int> char_row_number;
        int row=1;
        for(auto word : row_sequence){
            for(auto ch : word){
                char_row_number[ch] = row;
            }
            row++;
        }

        vector<string> result;
        for(auto singleWord: words){
            int size = singleWord.length();
            bool flag = true;
            for(auto i=0; i<size-1; i++){
                if(char_row_number[singleWord[i]]!=char_row_number[singleWord[i+1]]){
                    flag = false;
                }
            }
            if(flag){
                result.push_back(singleWord);
            }
        }
        return result;
    }
};