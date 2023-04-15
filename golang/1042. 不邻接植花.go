func gardenNoAdj(n int, paths [][]int) []int {
	ans := make([]int, n)
	adj := make([][]int, n)
	for i := 0; i < n; i++ {
		adj[i] = []int{}
	}
	for _, path := range paths {
		x := path[0] - 1
		y := path[1] - 1
		adj[x] = append(adj[x], y)
		adj[y] = append(adj[y], x)
	}
	for i := 0; i < n; i++ {
		colored := make([]bool, 5)
		for _, v := range adj[i] {
			colored[ans[v]] = true
		}
		for j := 1; j <= 4; j++ {
			if !colored[j] {
				ans[i] = j
				break
			}
		}
	}
	return ans
}