/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func dfs(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	}
	if p == nil || q == nil {
		return false
	}
	return p.Val == q.Val && dfs(p.Left, q.Right) && dfs(p.Right, q.Left)
}
func isSymmetric(root *TreeNode) bool {
	return dfs(root, root)
}