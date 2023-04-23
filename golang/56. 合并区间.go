func merge(intervals [][]int) [][]int {
    sort.Slice(intervals, func(i,j int) bool {
        return intervals[i][0]<intervals[j][0];
    })
    left,right:=0,0
    var ans [][]int
    for _,interval := range intervals{
        left=interval[0]
        right=interval[1]
        if len(ans)==0 || ans[len(ans)-1][1]<left {
            ans=append(ans,append([]int(nil),[]int{left,right}...))
        } else {
            right=max(right,ans[len(ans)-1][1])
            ans[len(ans)-1][1]=right
        }
    } 
    return ans
}
func max(x,y int) int{
    if x>y {
        return x
    }
    return y
}