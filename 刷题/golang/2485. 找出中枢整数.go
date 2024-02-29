func pivotInteger(n int) int {
	t := n * (n + 1) / 2
	x := int(math.Sqrt(float64(t)))
	if x*x == t {
		return x
	}
	return -1
}