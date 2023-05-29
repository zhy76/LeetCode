func averageValue(nums []int) int {
	sum := 0
	cnt := 0
	for _, num := range nums {
		if num%6 == 0 {
			sum += num
			cnt++
		}
	}
	if cnt == 0 {
		return 0
	}
	return sum / cnt
}