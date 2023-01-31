func checkXMatrix(grid [][]int) bool {
    n:=len(grid)
    for i,x:=range grid{
        for j,y:=range x{
            if i==j||(i+j)==n-1 {
                if y==0 {
                    return false
                }
            }else{
                if y!=0 {
                    return false
                }
            }
        }
    }
    return true
}