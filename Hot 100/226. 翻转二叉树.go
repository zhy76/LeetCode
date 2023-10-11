/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func dfs(root *TreeNode){
    if(root==nil){
        return
    }
    if(root.Left != nil) {
        dfs(root.Left)
    }
    if(root.Right != nil) {
        dfs(root.Right)
    }
    left := root.Left
    root.Left = root.Right
    root.Right = left
}
func invertTree(root *TreeNode) *TreeNode {
    dfs(root) 
    return root   
}