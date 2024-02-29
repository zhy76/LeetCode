type PriorityQueue []float64

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	return pq[i] > pq[j]
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x any) {
	*pq = append(*pq, x.(float64))
}

func (pq *PriorityQueue) Pop() any {
	old, n := *pq, len(*pq)
	x := old[n-1]
	*pq = old[0 : n-1]
	return x
}

func halveArray(nums []int) int {
	pq := &PriorityQueue{}
	sum, sum2 := 0.0, 0.0
	for _, x := range nums {
		heap.Push(pq, float64(x))
		sum += float64(x)
	}
	res := 0
	for sum2 < sum/2 {
		x := heap.Pop(pq).(float64)
		sum2 += x / 2
		heap.Push(pq, x/2)
		res++
	}
	return res
}