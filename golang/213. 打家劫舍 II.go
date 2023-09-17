func rob(nums []int) int {
    n := len(nums)
    if n==1 {
        return nums[0]
    } else if n==2 {
        return max(nums[0], nums[1])
    }
    return max(robRange(nums, 0, n-2), robRange(nums, 1, n-1))
}
func max(a ,b int)int {
    if a>b {
        return a
    }
    return b
}
func robRange(nums []int, start int, end int) int{
    first, second := nums[start], max(nums[start],nums[start+1])
    for i:=start+2; i<=end; i++ {
        t := second
        second=max(first+nums[i], second)
        first=t
    }
    return second
}