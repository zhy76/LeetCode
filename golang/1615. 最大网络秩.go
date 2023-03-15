func maximalNetworkRank(n int, roads [][]int) int {
    grid := make([][]bool, n)
    for i := range grid {
        grid[i] = make([]bool, n)
    }
    cnt := make([]int, n)
    for _, v := range roads {
        grid[v[0]][v[1]] = true
        grid[v[1]][v[0]] = true
        cnt[v[0]]++
        cnt[v[1]]++
    }
    res := 0
    for i := 0; i<n; i++ {
        for j := i+1; j<n; j++ {
            t := cnt[i]+cnt[j]
            if grid[i][j] {
                t-=1
            }
            res=max(res,t)
        }
    }
    return res;
}
func max(x, y int) int {
    if x>y {
        return x
    }
    return y
}