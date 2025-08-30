class Solution {
    public long myPow(long x, long n) {
        if (n == 0)
            return 1;

        long half = myPow(x, n / 2);

        if (n % 2 == 0) {
            return half * half;
        } else {
            if (n > 0) {
                return half * half * x;
            } else {
                return 0;
            }
        }
    }

    public long stringToNumber(StringBuilder s) {
        long n = s.length();
        long result = 0;
        long pow = 0;

        for (long i = n - 1; i >= 0; i--) {
            if (s.charAt((int) i) == '1') {
                result += myPow(2, pow);
            }
            pow++;
        }
        return result;
    }

    public StringBuilder DecimalToBinary(int n) {
        StringBuilder binary = new StringBuilder();
        while (n != 0) {
            binary.append(n % 2);
            n = n / 2;
        }
        binary.reverse();
        while (binary.length() < 32) {
            binary.insert(0, '0');
        }
        return binary;
    }

    public int reverseBits(int n) {
        StringBuilder binaryForm = DecimalToBinary(n);
        binaryForm.reverse(); // actual reversal of bits
        return Math.toIntExact(stringToNumber(binaryForm));
    }

}