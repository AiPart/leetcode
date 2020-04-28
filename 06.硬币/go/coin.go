func waysToChange(n int) int {
	dp := make([]int, 1000000)
	dp[0] = 1
	coins := []int{1, 5, 10, 25}
	for _, coin := range coins {
		//按照一定次序，把硬币的排列情况进行累加，最后得到n的排列
		for i := coin; i <= n; i++ {
			dp[i] = dp[i] + dp[i-coin]
		}
	}
	return dp[n] % 1000000007
}