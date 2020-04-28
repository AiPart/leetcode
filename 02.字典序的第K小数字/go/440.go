//author : baronliu，问题核心在于字典排序里，数字+1，indx增加的量；以及index+1，数字增加的量需要重新换算

func findKthNumber(n int, k int) int {
	p, result := 1, 1
	for p < k {
		c := getCount(result, n)
		if p+c > k {
			//说明锁定范围就在此前缀
			p += 1
			result *= 10
		} else {
			//说明范围不在此前缀，需要进位
			p += c
			result += 1
		}
	}
	return result
}

func getCount(prefix int, n int) int {
	cnt := 0
	for a, b := prefix, prefix+1; a <= n; a, b = a*10, b*10 {
		cnt += min(b, n+1) - a
	}
	return cnt
}

func min(a int, b int) int {
	if a >= b {
		return b
	}
	return a
}