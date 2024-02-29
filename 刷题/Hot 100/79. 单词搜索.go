func exist(board [][]byte, word string) bool {
	dir := [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
	m, n := len(board), len(board[0])
	vis := make([][]bool, m+1)
	for i := range vis {
		vis[i] = make([]bool, n+1)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			vis[i][j] = false
		}
	}
	flag := false
	var dfs func(int, int, int)
	dfs = func(x int, y int, ind int) {
		if board[x][y] != word[ind] {
			return
		}
		if ind == len(word)-1 {
			flag = true
			return
		}
		for i := 0; i < 4; i++ {
			tx := x + dir[i][0]
			ty := y + dir[i][1]
			if tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] {
				continue
			}
			vis[tx][ty] = true
			dfs(tx, ty, ind+1)
			vis[tx][ty] = false
		}
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			vis[i][j] = true
			dfs(i, j, 0)
			vis[i][j] = false
			if flag {
				return true
			}
		}
	}
	return false
}