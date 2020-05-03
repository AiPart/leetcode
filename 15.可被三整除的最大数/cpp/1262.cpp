class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int dp[3] = {0};
        int tmp[3] = {0};

        for (int n: nums) {
            memcpy(tmp, dp, sizeof(int)*3);

            for (int i = 0; i < 3; ++i) {
                if ((n + tmp[i]) % 3 == 0) {
                    dp[0] = max(n+tmp[i], dp[0]);
                } else if ((n + tmp[i]) % 3 == 1) {
                    dp[1] = max(n+tmp[i], dp[1]);
                } else {
                    dp[2] = max(n+tmp[i], dp[2]);
                }
            }
        }
        return dp[0];
    }
};
