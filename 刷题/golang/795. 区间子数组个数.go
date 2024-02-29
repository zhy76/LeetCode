func numSubarrayBoundedMax(nums []int, left int, right int) int {
    count := func(lower int) (res int) {
        cur := 0
        for _, x := range nums {
            if x <= lower {
                cur++
            } else {
                cur = 0
            }
            res += cur
        }
        return
    }
    return count(right) - count(left-1)
}