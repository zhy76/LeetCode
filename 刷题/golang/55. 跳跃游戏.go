func canJump(nums []int) bool {
    maxD:=0
    n:=len(nums)
    for i := range nums {
        if i<=maxD {
            maxD = max(maxD, i+nums[i])
            if maxD >= n-1 {
                return true
            }
        }
    }
    return false
}
func max(x, y int) int {
    if x>y {
        return x
    }
    return y
}