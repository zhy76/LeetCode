func largestLocal(grid [][]int) [][]int {
    n:=len(grid)
    ans:=make([][]int,n-2)
    for i:=0;i<n-2;i++{
        row:=make([]int,n-2)
        for j:=0;j<n-2;j++{
            mx:=grid[i][j]
            for k:=i;k<i+3;k++{
                for h:=j;h<j+3;h++{
                    if grid[k][h]>mx{
                        mx=grid[k][h]
                    }
                }
            }
            row[j]=mx
        }
        ans[i]=row
    }
    return ans
}