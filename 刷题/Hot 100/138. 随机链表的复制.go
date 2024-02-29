var cachedNode map[*Node]*Node

func deepCopy(node *Node) *Node {
    if node == nil {
        return nil
    }
    if n, has := cachedNode[node]; has {
        return n
    }
    newNode := &Node{Val: node.Val}
    cachedNode[node] = newNode
    newNode.Next = deepCopy(node.Next)
    newNode.Random = deepCopy(node.Random)
    return newNode
}

func copyRandomList(head *Node) *Node {
    cachedNode = map[*Node]*Node{}
    return deepCopy(head)
}

// 法2
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

 func copyRandomList(head *Node) *Node {
    // mp := map[*Node]*Node{}
    mp:=make(map[*Node]*Node)
    p:=head
    for p!=nil {
        tmp := &Node{Val: p.Val}
        mp[p] = tmp
        p = p.Next
    }
    p=head
    for p!= nil {
        mp[p].Next = mp[p.Next]
        mp[p].Random = mp[p.Random]
        p = p.Next
    }
    return mp[head]
}