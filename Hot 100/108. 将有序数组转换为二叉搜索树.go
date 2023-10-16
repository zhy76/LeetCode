/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func sortedArrayToBST(nums []int) *TreeNode {
    var dfs func(int,int)*TreeNode
    dfs = func(left, right int) *TreeNode {
        if left > right {
            return nil
        }
        mid:=(left+right+1)/2
        root := &TreeNode{Val: nums[mid]}
        root.Left=dfs(left,mid-1)
        root.Right=dfs(mid+1,right)
        return root
    }
    return dfs(0,len(nums)-1)
}