/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func diameterOfBinaryTree(root *TreeNode) int {
    ans := 1
    var depth func(*TreeNode) int
    depth = func (root *TreeNode) int {
        if root == nil {
            return 0
        }
        L := depth(root.Left)
        R := depth(root.Right)
        ans = max(ans, L + R + 1)
        return max(L, R)+1
    }
    depth(root)
    return ans-1
}
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}