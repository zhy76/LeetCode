func largestSumOfAverages(nums []int, k int) float64 {
    n:=len(nums)
    prefix:=make([]float64,n+1)
    for i,x:=range nums{
        prefix[i+1]=prefix[i]+float64(x)
    }
    dp:=make([][]float64,n+1)
    for i:=range dp{
        dp[i]=make([]float64,k+1)
    }
    for i:=1;i<=n;i++ {
        dp[i][1]=prefix[i]/float64(i)
    }
    for j:=2;j<=k;j++{
        for i:=j;i<=n;i++{
            for x:=j-1;x<i;x++{
                dp[i][j]=math.Max(dp[i][j],dp[x][j-1]+(prefix[i]-prefix[x])/float64(i-x))
            }
        }
    }
    return dp[n][k]
}