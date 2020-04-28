/*
 * @lc app=leetcode.cn id=5 lang=golang
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.90%)
 * Likes:    1788
 * Dislikes: 0
 * Total Accepted:    190.1K
 * Total Submissions: 663.2K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 * 示例 1：
 *
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 *
 *
 * 示例 2：
 *
 * 输入: "cbbd"
 * 输出: "bb"
 *
 *
 */

// @lc code=start
func longestPalindrome(s string) string {
	if len(s) <= 1 {
		return s
	}
	result := ""
	for i := 0; i < len(s)-1; i++ {
		l := getInfo(s, i, i)
		if len(l) > len(result) {
			result = l
		}
		l = getInfo(s, i, i+1)
		if len(l) > len(result) {
			result = l
		}
	}

	return result
}

func getInfo(s string, start int, end int) string {
	for start >= 0 && end <= len(s)-1 && s[start] == s[end] {
		start--
		end++
	}
	return s[start+1 : end]
}