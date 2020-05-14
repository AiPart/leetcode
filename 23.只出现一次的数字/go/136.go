func singleNumber(nums []int) int {
	m := make(map[int]int)
	for _, num := range nums {
		m[num]++
	}
	result := 0
	for k, v := range m {
		if v == 1 {
			result = k
			break
		}
	}
	return result
}