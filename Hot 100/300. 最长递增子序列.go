func lengthOfLIS(nums []int) int {
    n := len(nums)
    dp := make([]int, n+1)
    for i:=0; i<n; i++ {
        dp[i] = 1
        for j:=0; j<i; j++ {
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i], dp[j]+1)
            }
        }
    }
    ans := 0
    for i:=0; i<n; i++ {
        ans = max(ans, dp[i])
    }
    return ans
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}