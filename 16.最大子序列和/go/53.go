func maxSubArray(nums []int) int {
	if len(nums) < 1 {
		return 0
	}
	if len(nums) == 1 {
		return nums[0]
	}

	max, subMax := nums[0], nums[0]
	for i := 1; i < len(nums); i++ {
		if subMax <= 0 {
			subMax = nums[i]
		} else {
			subMax += nums[i]
		}

		if subMax > max {
			max = subMax
		}
	}

	return max
}