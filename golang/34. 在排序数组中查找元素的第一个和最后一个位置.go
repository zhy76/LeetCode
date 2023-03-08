func searchRange(nums []int, target int) []int {
    n := len(nums)
    ind1 := binarySearch(nums, target, true)
    ind2 := binarySearch(nums, target, false)
    if ind1 <= ind2 - 1 && ind2 - 1 < n && nums[ind1] == target && nums[ind2 - 1] == target {
        return []int{ind1, ind2 - 1}
    }
    return []int{-1, -1}
}
func binarySearch(nums []int, target int, lower bool) int{
    n := len(nums)
    left, right := 0, n-1
    for left <= right {
        mid := (left + right) / 2
        if nums[mid] > target || (lower && nums[mid] >= target) {
            right = mid - 1
        } else {
            left = mid + 1
        }
    }
    return left
}