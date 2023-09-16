func rob(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    if len(nums) == 1 {
        return nums[0]
    }
    first, second := nums[0], max(nums[0],nums[1])
    for i:=2; i<len(nums); i++ {
        t:=max(first+nums[i], second)
        first=second
        second=t
    }
    return second
}
func max(a, b int) int {
    if a>b {
        return a
    }
    return b
}