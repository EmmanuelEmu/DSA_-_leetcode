class Solution {
public:
    bool isPerfectSquare(int num) {
        auto rootValue = sqrt(num);
        auto extra = rootValue - int(rootValue);

        if (extra > 0) {
            return false;
        }
        return true;
    }
};