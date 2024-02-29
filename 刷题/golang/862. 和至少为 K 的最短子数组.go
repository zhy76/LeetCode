func shortestSubarray(nums []int, k int) int {
    n:=len(nums)
    preSum:=make([]int,n+1)
    for i, num:=range nums{
        preSum[i+1]=preSum[i]+num
    }
    ans:= n+1
    q:=[]int{}
    for i, curSum:=range preSum{
        for len(q)>0 && curSum-preSum[q[0]] >=k{
            ans=min(ans,i-q[0])
            q=q[1:]
        }
        for len(q)>0 && preSum[q[len(q)-1]]>=curSum{
            q=q[:len(q)-1]
        }
        q=append(q,i)
    }
    if ans<n+1{
        return ans
    }else {
        return  -1
    }
}
func min(a,b int) int{
    if a<b{
        return a
    }
    return b
}