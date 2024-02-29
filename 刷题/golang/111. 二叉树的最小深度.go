func minDepth(root *TreeNode) int {
	if root == nil {
		  return 0
	 }
	 q := []*TreeNode{root}
	 // root 本身就是一层，depth 初始化为 1
	 depth := 1
 
	 for len(q) != 0 {
		 sz := len(q)
		 /* 将当前队列中的所有节点向四周扩散 */
		 for i := 0; i < sz; i++ {
			 cur := q[0]
			 q = q[1:]
			 /* 判断是否到达终点 */
			 if cur.Left == nil && cur.Right == nil {
				 return depth
			 }
			 /* 将 cur 的相邻节点加入队列 */
			 if cur.Left != nil {
				 q = append(q, cur.Left)
			 }
			 if cur.Right != nil {
				 q = append(q, cur.Right)
			 }
		 }
		 /* 这里增加步数 */
		 depth++
	 }
	 return depth
 }
 