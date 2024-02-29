func twoSum(nums []int, target int) []int {
	mp := map[int]int{}
	for i, x := range nums {
		if p, ok := mp[target-x]; ok {
			return []int{p, i}
		}
		mp[x] = i
	}
	return nil
}