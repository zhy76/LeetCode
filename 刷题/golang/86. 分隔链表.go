/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func partition(head *ListNode, x int) *ListNode {
    dummy1:=&ListNode{-1,nil}
    dummy2:=&ListNode{-1,nil}
    small, large:=dummy1, dummy2
    p:=head
    for p!=nil {
        if p.Val < x {
            small.Next = p
            small = small.Next
        } else {
            large.Next = p
            large = large.Next
        }
        p=p.Next
    }
    large.Next=nil
    small.Next=dummy2.Next
    return dummy1.Next
}