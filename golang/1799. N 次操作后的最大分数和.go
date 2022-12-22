func maxScore(nums []int) int {
    m:=len(nums)
    g:=make([][]int,m)
    for i:=0;i<m;i++{
        g[i]=make([]int,m)
    }
    dp:=make([]int,1<<m)
    for i:=0;i<m;i++{
        for j:=i+1;j<m;j++{
            g[i][j]=gcd(nums[i],nums[j])
        }
    }
    all:=1<<m
    for s:=0;s<all;s++{
        cnt:=bits.OnesCount(uint(s))
        if cnt&1==1{
            continue
        }
        for i:=0;i<m;i++{
            if (s>>i)&1==1{
                for j:=i+1;j<m;j++{
                    if (s>>j)&1==1{
                        dp[s]=max(dp[s],dp[s^(1<<i)^(1<<j)]+cnt/2*g[i][j])
                    }
                }
            }
        }
    }
    return dp[all-1]
    
}
func max(a,b int) int {
    if(a>b) {
        return a
    }
    return b
}
func gcd(a,b int) int{
    if(b==0){
        return a
    }
    return gcd(b,a%b)
}