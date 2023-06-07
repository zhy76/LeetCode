func miceAndCheese(reward1 []int, reward2 []int, k int) int {
	n := len(reward1)
	diff := make([]int, n)
	ans := 0
	for i, r := range reward2 {
		ans += r
		diff[i] = reward1[i] - r
	}
	sort.Ints(diff)
	for i := 1; i <= k; i++ {
		ans += diff[n-i]
	}
	return ans
}