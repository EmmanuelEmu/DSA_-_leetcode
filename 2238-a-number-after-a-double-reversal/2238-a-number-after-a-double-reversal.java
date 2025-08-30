class Solution {

    public int reverseNumber(int num){
        int result = 0;
        while(num!=0){
            result = (result*10)+(num%10);
            num/=10;
        }
        return result;
    }
    public boolean isSameAfterReversals(int num) {
        int reverseForm = reverseNumber(num);
        String trimingLeadingZeros = String.valueOf(reverseForm);

        return num == reverseNumber(Integer.parseInt(trimingLeadingZeros));
    }
}