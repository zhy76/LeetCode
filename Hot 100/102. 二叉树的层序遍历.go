/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
	ans := [][]int{}
	if root == nil {
		return ans
	}
	qu := []*TreeNode{root}
	for i := 0; len(qu) > 0; i++ {
		ans = append(ans, []int{})
		p := []*TreeNode{}
		for j := 0; j < len(qu); j++ {
			node := qu[j]
			ans[i] = append(ans[i], node.Val)
			if node.Left != nil {
				p = append(p, node.Left)
			}
			if node.Right != nil {
				p = append(p, node.Right)
			}
		}
		qu = p
	}
	return ans
}