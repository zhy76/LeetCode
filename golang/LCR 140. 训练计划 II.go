func trainningPlan(head *ListNode, cnt int) *ListNode {
    fast, slow := head, head
    for fast != nil && cnt > 0 {
        fast = fast.Next
        cnt--
    }
    for fast != nil {
        fast = fast.Next
        slow = slow.Next
    }
    return slow
}