func solveNQueens(n int) [][]string {
    res := [][]string{}
    track := make([]string, n)
    for i:=0; i<n; i++ {
        track[i] = strings.Repeat(".", n)
    }
    backtrack(&res, 0, track)
    return res
}

func backtrack(res *[][]string, row int, track []string) {
    if row == len(track) {
        newRow := make([]string, len(track))
        copy(newRow, track)
        *res = append(*res, newRow)
        return
    } 
    n:=len(track[row])
    for j:=0; j<n; j++ {
        if !isValid(track, row, j, n) {
            continue
        }
        // 做选择
        newLine := []byte(track[row])
        newLine[j] = 'Q'
        track[row] = string(newLine)
        backtrack(res, row+1, track)
        newLine[j] = '.'
        track[row] = string(newLine)
    }
}

func isValid(track []string, row int, col int, n int) bool {
    for i:=0 ; i<n; i++ {
        if track[i][col] == 'Q'{
            return false
        }
    }
    for i, j := row-1, col+1; i >= 0 && j < n; i, j = i-1, j+1 {
        if track[i][j] == 'Q' {
            return false
        }
    }
    for i, j:=row-1, col-1; i>=0 && j>=0; i, j = i-1, j-1 {
        if track[i][j] == 'Q' {
            return false
        }
    }
    return true
}