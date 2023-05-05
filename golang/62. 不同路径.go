func uniquePaths(m int, n int) int {
	cur := make([]int, 105)
	for i := 0; i < m; i++ {
		cur[i] = 1
	}
	for j := 0; j < n; j++ {
		cur[j] = 1
	}
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			cur[j] += cur[j-1]
		}
	}
	return cur[n-1]
}