func largestValsFromLabels(values []int, labels []int, numWanted int, useLimit int) int {
	n := len(values)
	ids := make([]int, n)
	for i := 0; i < n; i++ {
		ids[i] = i
	}
	sort.Slice(ids, func(i, j int) bool {
		return values[ids[i]] > values[ids[j]]
	})
	ans, choose := 0, 0
	cnt := make(map[int]int)
	for i := 0; i < n; i++ {
		label := labels[ids[i]]
		if cnt[label] == useLimit {
			continue
		}
		choose++
		ans += values[ids[i]]
		cnt[label]++
		if choose == numWanted {
			break
		}
	}
	return ans
}