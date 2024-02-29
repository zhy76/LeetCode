func maxValue(grid [][]int) int {
    m, n := len(grid), len(grid[0])
    dp := make([][]int, m)
    for i := range dp {
        dp[i] = make([]int, n)
    }
    for i, x := range grid {
        for j, y := range x {
            if i > 0 {
                dp[i][j] = max(dp[i][j], dp[i-1][j])
            }
            if j > 0 {
                dp[i][j] = max(dp[i][j], dp[i][j-1])
            } 
            dp[i][j] += y
        }
    }
    return dp[m-1][n-1]
}
func max (x, y int) int {
    if x > y {
        return x
    }
    return y
}