func prevPermOpt1(arr []int) []int {
	n := len(arr)
	for i := n - 2; i >= 0; i-- {
		if arr[i+1] < arr[i] {
			j := n - 1
			for arr[j] >= arr[i] || arr[j] == arr[j-1] {
				j--
			}
			arr[i], arr[j] = arr[j], arr[i]
			break
		}
	}
	return arr
}