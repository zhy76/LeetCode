func minPathSum(grid [][]int) int {
	dp := make([][]int, 205)
	for i := range dp {
		dp[i] = make([]int, 205)
	}
	m, n := len(grid), len(grid[0])
	dp[0][0] = grid[0][0]
	for i := 1; i < m; i++ {
		dp[i][0] = dp[i-1][0] + grid[i][0]
	}
	for j := 1; j < n; j++ {
		dp[0][j] = dp[0][j-1] + grid[0][j]
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
		}
	}
	return dp[m-1][n-1]
}
func min(x, y int) int {
	if x > y {
		return y
	}
	return x
}