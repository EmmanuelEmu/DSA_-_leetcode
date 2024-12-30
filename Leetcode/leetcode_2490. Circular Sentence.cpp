#include <bits/stdc++.h>
using namespace std;

bool isCircularSentence(string sentence)
{
     std::vector<std::string> words;
    
    // Create a string stream from the input string
    std::istringstream stream(sentence);
    std::string word;

    // Extract words from the stream and add them to the vector
    while (stream >> word) {
        words.push_back(word);
    }

    if(words.size()==1){
        string word = words[0];
        return word[0] == word[word.size()-1];
    } else{
        for(auto i=0; i<words.size(); i++){
            string firstWord = words[i];
            string secondWord = words[(i+1)%words.size()];
            if(firstWord[firstWord.size()-1] != secondWord[0]){
                return false;
            }
        }
        if(words[0][0] != words[words.size()-1][words[words.size()-1].size()-1]){
            return false;
        }
        return true;
    }
}

int main()
{

    return 0;
}