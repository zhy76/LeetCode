/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 var(
    f = make(map[*TreeNode]int)
    g = make(map[*TreeNode]int)
)
func dfs(root *TreeNode){
    if root == nil {
        return 
    }
    dfs(root.Left)
    dfs(root.Right)
    f[root]=root.Val+g[root.Left]+g[root.Right]
    g[root]=max(f[root.Left],g[root.Left]) + max(f[root.Right], g[root.Right])
}

func rob(root *TreeNode) int {
    dfs(root)
    return max(f[root], g[root])
}

func max(x, y int) int {
    if x>y {
        return x
    }
    return y
}