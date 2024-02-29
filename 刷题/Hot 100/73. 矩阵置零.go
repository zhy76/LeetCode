func setZeroes(matrix [][]int)  {
    flag_row0, flag_col0 := false, false
    m, n := len(matrix), len(matrix[0])
    for i:=0; i<m; i++ {
        if matrix[i][0]==0 {
            flag_col0 = true
            break
        }
    }
    for j:=0; j<n; j++ {
        if matrix[0][j]==0 {
            flag_row0 = true
            break
        }
    }
    for i:=1; i<m; i++{
        for j:=1; j<n; j++ {
            if matrix[i][j] == 0 {
                matrix[i][0], matrix[0][j] = 0, 0 
            }
        }
    }
    for i:=1; i<m; i++ {
        for j:=1; j<n; j++ {
            if matrix[i][0]==0 || matrix[0][j]==0 {
                matrix[i][j] = 0
            }
        }
    }
    if flag_col0 {
        for i:=0; i<m; i++ {
            matrix[i][0] = 0
        }
    }
    if flag_row0 {
        for j:=0; j<n; j++ {
            matrix[0][j] = 0
        }
    }
}