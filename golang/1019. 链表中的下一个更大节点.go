/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func nextLargerNodes(head *ListNode) []int {
	var ans []int
	var stack [][]int
	cur := head
	ind := -1
	for cur != nil {
		ind++
		ans = append(ans, 0)
		for len(stack) > 0 && stack[len(stack)-1][0] < cur.Val {
			ans[stack[len(stack)-1][1]] = cur.Val
			stack = stack[:len(stack)-1]
		}
		stack = append(stack, []int{cur.Val, ind})
		cur = cur.Next
	}
	return ans
}