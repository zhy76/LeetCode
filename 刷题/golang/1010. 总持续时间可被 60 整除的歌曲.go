func numPairsDivisibleBy60(time []int) (res int) {
	count := map[int]int{}
	for _, t := range time {
		res += count[(60-t%60)%60]
		count[t%60]++
	}
	return
}