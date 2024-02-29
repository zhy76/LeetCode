func countPoints(points [][]int, queries [][]int) []int {
    n:=len(queries)
    ans:=make([]int,n)
    for i,x:=range queries{
        for _,y:=range points{
            cx:=x[0]-y[0]
            cy:=x[1]-y[1]
            r:=x[2]
            if cx*cx+cy*cy<=r*r{
                ans[i]++
            }
        }
    }
    return ans
}