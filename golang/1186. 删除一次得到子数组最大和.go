func maximumSum(arr []int) int {
    dp0,dp1,res:=arr[0],0,arr[0]
    for i:=1;i<len(arr);i++ {
        dp1=max(dp0,dp1+arr[i])
        dp0=max(dp0,0)+arr[i]
        res=max(res,max(dp0,dp1))
    }
    return res
}
func max(a,b int) int {
    if a>b {
        return a
    }
    return b
}