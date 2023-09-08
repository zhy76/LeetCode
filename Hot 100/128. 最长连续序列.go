func longestConsecutive(nums []int) int {
	numSet := map[int]bool{}
	for _, num := range nums {
		numSet[num] = true
	}
	ans := 0
	for num := range numSet {
		if !numSet[num-1] {
			curnum := num
			len := 1
			for numSet[curnum+1] {
				len++
				curnum++
			}
			ans = max(ans, len)
		}
	}
	return ans
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}