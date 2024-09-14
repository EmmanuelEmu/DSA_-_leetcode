class Solution {
public:
    int nextGen(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = nextGen(n);

        while (fast != 1 && slow != fast) {
            slow = nextGen(slow);
            fast = nextGen(nextGen(fast));
        }

        return fast == 1;
    }
};