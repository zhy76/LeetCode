func minNumber(nums1 []int, nums2 []int) int {
	mp1 := [10]int{}
	mp2 := [10]int{}
	for _, num := range nums1 {
		mp1[num] = 1
	}
	for _, num := range nums2 {
		mp2[num] = 1
	}
	a, b := 0, 0
	for i := 1; i <= 9; i++ {
		if mp1[i] == 1 && mp2[i] == 1 {
			return i
		} else if a == 0 && mp1[i] == 1 {
			a = i
		} else if b == 0 && mp2[i] == 1 {
			b = i
		}
	}
	return min(a*10+b, b*10+a)
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}