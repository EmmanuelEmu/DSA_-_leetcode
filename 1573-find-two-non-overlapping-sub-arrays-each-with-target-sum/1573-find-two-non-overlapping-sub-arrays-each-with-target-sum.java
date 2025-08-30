class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;
        int INF = (int) 1e9;

        int[] best = new int[n];
        Arrays.fill(best, INF);

        int left = 0, sum = 0;
        int ans = INF;
        int minLen = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target && left <= right) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int currLen = right - left + 1;
                if (left > 0 && best[left - 1] != INF) {
                    ans = Math.min(ans, best[left - 1] + currLen);
                }
                minLen = Math.min(minLen, currLen);
            }

            best[right] = minLen; // best up to index right
        }

        return ans == INF ? -1 : ans;
    }
}