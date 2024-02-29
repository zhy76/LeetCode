/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func delNodes(root *TreeNode, to_delete []int) []*TreeNode {
	toDeleted := make(map[int]bool)
	for _, val := range to_delete {
		toDeleted[val] = true
	}
	var ans []*TreeNode
	var dfs func(node *TreeNode, is_root bool) *TreeNode
	dfs = func(node *TreeNode, is_root bool) *TreeNode {
		if node == nil {
			return nil
		}
		deleted := false
		if toDeleted[node.Val] {
			deleted = true
		}
		node.Left = dfs(node.Left, deleted)
		node.Right = dfs(node.Right, deleted)
		if deleted {
			node = nil
		} else {
			if is_root {
				ans = append(ans, node)
			}
		}
		return node
	}
	dfs(root, true)
	return ans
}