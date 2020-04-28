func generateParenthesis(n int) []string {
	var result []string
	if n == 0 {
		return result
	}
	dfs(n, n, "", &result)
	return result
}

func dfs(left int, right int, current string, result *[]string) {
	if left == 0 && right == 0 {
		//到底后写入
		*result = append(*result, current)
	}

	//左括号用完了
	if left > 0 {
		dfs(left-1, right, current+"(", result)
	}

	//右括号
	if right > left {
		dfs(left, right-1, current+")", result)
	}
}