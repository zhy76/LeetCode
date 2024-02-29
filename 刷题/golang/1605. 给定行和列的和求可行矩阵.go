func restoreMatrix(rowSum []int, colSum []int) [][]int {
    r, c := len(rowSum), len(colSum)
    gird := make([][]int, r)
    for i := range gird {
        gird[i] = make([]int, c)
    }
    i, j := 0, 0
    for i<r && j<c {
        x := min(rowSum[i], colSum[j])
        gird[i][j] = x
        rowSum[i] -= x
        colSum[j] -= x
        if rowSum[i] == 0 {
            i++
        }
        if colSum[j] == 0{
            j++
        }
    }
    return gird
}
func min(x, y int) int {
    if x<y {
        return x
    }
    return y
}