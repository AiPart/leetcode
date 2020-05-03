class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return 0;
        } else if (size == 1) { // 这个else if也可以去掉，加上会加快一点点速度
            return nums[0];
        }
        int* dp = new int[size];
        memset(dp, 0, sizeof(int)*size);
        dp[0] = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < size; ++i) {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            max_sum = max(max_sum, dp[i]);
        }
        return max_sum;
    }
};
