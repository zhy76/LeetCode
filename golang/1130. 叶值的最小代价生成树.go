func mctFromLeafValues(arr []int) int {
	res, stk := 0, []int{}
	for _, x := range arr {
		for len(stk) > 0 && stk[len(stk)-1] <= x {
			if len(stk) == 1 || stk[len(stk)-2] > x {
				res += stk[len(stk)-1] * x
			} else {
				res += stk[len(stk)-2] * stk[len(stk)-1]
			}
			stk = stk[:len(stk)-1]
		}
		stk = append(stk, x)
	}
	for len(stk) > 1 {
		res += stk[len(stk)-2] * stk[len(stk)-1]
		stk = stk[:len(stk)-1]
	}
	return res
}