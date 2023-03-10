func permute(nums []int) [][]int {
    n := len(nums)
    var ans [][]int
    var dfs func(int)
    dfs = func(ind int) {
        if ind == n {
            ans = append(ans, append([]int(nil), nums...))
            return
        }
        for i := ind; i < n; i++ {
            nums[i], nums[ind] = nums[ind], nums[i]
            dfs(ind+1)
            nums[ind], nums[i] = nums[i], nums[ind]
        } 
    }
    dfs(0)
    return ans
}