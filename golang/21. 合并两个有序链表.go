/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    head:=&ListNode{-1,nil}
    p:=head
    p1, p2:=list1, list2
    for p1!=nil && p2!=nil {
        if p1.Val < p2.Val {
            p.Next=p1
            p1=p1.Next
        } else {
            p.Next=p2
            p2=p2.Next
        }
        p=p.Next
    }
    if p1!=nil {
        p.Next=p1
    }
    if p2!=nil {
        p.Next=p2
    }
    return head.Next
}