/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var ans int

func distributeCoins(root *TreeNode) int {
	ans = 0
	dfs(root)
	return ans
}
func dfs(root *TreeNode) int {
	leftmove, rightmove := 0, 0
	if root == nil {
		return 0
	}
	if root.Left != nil {
		leftmove = dfs(root.Left)
	}
	if root.Right != nil {
		rightmove = dfs(root.Right)
	}
	ans += abs(leftmove) + abs(rightmove)
	return leftmove + rightmove + root.Val - 1
}
func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}