func checkDistances(s string, distance []int) bool {
	firstInd := make([]int, 26)
	for i := 0; i < len(s); i++ {
		idx := s[i] - 'a'
		if firstInd[idx] != 0 && i-firstInd[idx] != distance[idx] {
			return false
		}
		firstInd[idx] = i + 1
	}
	return true
}