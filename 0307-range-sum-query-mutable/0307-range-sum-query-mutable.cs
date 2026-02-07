public class NumArray {
    private int[] bit;
    private int[] nums;
    private int n;

    public NumArray(int[] nums) {
        this.nums = nums;
        this.n = nums.Length;
        this.bit = new int[n + 1]; // BIT is usually 1-indexed

        for (int i = 0; i < n; i++) {
            Add(i + 1, nums[i]);
        }
    }

    private void Add(int index, int val) {
        while (index <= n) {
            bit[index] += val;
            index += index & -index; // The "magic" step: move to the next responsible node
        }
    }

    public void Update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        Add(index + 1, diff);
    }

    private int GetPrefixSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & -index;
        }
        return sum;
    }

    public int SumRange(int left, int right) {
        return GetPrefixSum(right + 1) - GetPrefixSum(left);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.Update(index,val);
 * int param_2 = obj.SumRange(left,right);
 */