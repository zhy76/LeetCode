func minimumBoxes(n int) int {
	cur, i, j := 1, 1, 1
	for n > cur {
		n -= cur
		i++
		cur += i
	}
	cur = 1
	for n > cur {
		n -= cur
		j++
		cur++
	}
	return (i-1)*i/2 + j
}