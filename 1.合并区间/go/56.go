import "sort"

//author : baronliu

func merge(intervals [][]int) [][]int {
	var result [][]int

	if len(intervals) < 1 {
		return result
	}

	sort.Slice(intervals, func(i int, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})

	for i := 0; i < len(intervals); i++ {
		temp := intervals[i]
		for j := i + 1; j < len(intervals); j++ {
			if intervals[j][0] > temp[1] {
				break
			} else if intervals[j][1] > temp[1] {
				temp[1] = intervals[j][1]
			}
			i++
		}

		result = append(result, temp)
	}
	return result
}