class Solution {
public:
    int waysToChange(int n) {
        const int N = 1000000;
        const int mod = 1000000007;
        int coins[4] = {1, 5, 10, 25};
        int dp[N+1] = {1};

        for (int i = 0; i < 4; ++i) {
            for (int j = coins[i]; j <= n; j++) {
                dp[j] = (dp[j] + dp[j-coins[i]]) % mod;
            }
        }
        return dp[n];
    }
};
