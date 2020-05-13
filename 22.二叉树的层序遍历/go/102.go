func levelOrder(root *TreeNode) [][]int {
	var result [][]int
	if root == nil {
		return result
	}
	var queue []*TreeNode
	queue = append(queue, root)
	for len(queue) > 0 {
		var newQueue []*TreeNode
		var arr []int
		for i := 0; i < len(queue); i++ {
			arr = append(arr, queue[i].Val)
			if queue[i].Left != nil {
				newQueue = append(newQueue, queue[i].Left)
			}

			if queue[i].Right != nil {
				newQueue = append(newQueue, queue[i].Right)
			}
		}
		queue = newQueue
		result = append(result, arr)
	}

	return result
}