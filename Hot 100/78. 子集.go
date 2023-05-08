func subsets(nums []int) [][]int {
	ans := [][]int{}
	var dfs func(int, []int)
	dfs = func(ind int, tmp []int) {
		if ind == len(nums) {
			ans = append(ans, append([]int(nil), tmp...))
			return
		}
		tmp = append(tmp, nums[ind])
		dfs(ind+1, tmp)
		tmp = tmp[:len(tmp)-1]
		dfs(ind+1, tmp)
	}
	dfs(0, []int{})
	return ans
}