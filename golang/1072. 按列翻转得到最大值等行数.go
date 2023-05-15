func maxEqualRowsAfterFlips(matrix [][]int) int {
	mp := make(map[string]int)
	m, n := len(matrix), len(matrix[0])
	for i := 0; i < m; i++ {
		t := make([]byte, n)
		for j := 0; j < n; j++ {
			t[j] = byte('0' + matrix[i][0] ^ matrix[i][j])
		}
		mp[string(t)]++
	}
	ans := 0
	for _, v := range mp {
		ans = max(ans, v)
	}
	return ans
}
func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}