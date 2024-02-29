func jump(nums []int) int {
    maxPos, end, step, n := 0, 0, 0, len(nums)
    for i:=0; i<n-1; i++ {
        if maxPos >= i {
            maxPos = max(maxPos, i+nums[i])
            if i == end {
                end=maxPos
                step++
            }
        }
    }
    return step
}

func max(a, b int) int {
    if a>b {
        return a
    }
    return b
}