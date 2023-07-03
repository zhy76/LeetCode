/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	st1 := make([]int, 0)
	st2 := make([]int, 0)
	for l1 != nil {
		st1 = append(st1, l1.Val)
		l1 = l1.Next
	}
	for l2 != nil {
		st2 = append(st2, l2.Val)
		l2 = l2.Next
	}
	var ans *ListNode
	carry := 0
	for len(st1) != 0 || len(st2) != 0 || carry != 0 {
		a, b := 0, 0
		if len(st1) != 0 {
			a = st1[len(st1)-1]
			st1 = st1[:len(st1)-1]
		}
		if len(st2) != 0 {
			b = st2[len(st2)-1]
			st2 = st2[:len(st2)-1]
		}
		t := a + b + carry
		carry = t / 10
		curnode := &ListNode{Val: t % 10, Next: ans}
		ans = curnode
	}
	return ans
}