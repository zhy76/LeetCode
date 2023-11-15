func longestAlternatingSubarray(nums []int, threshold int) int {
    res, dp := 0, 0
    for l := len(nums) - 1; l >= 0; l-- {
        if nums[l] > threshold {
            dp = 0
        } else if l == len(nums) - 1 || nums[l] % 2 != nums[l + 1] % 2 {
            dp++
        } else {
            dp = 1
        }
        if nums[l] % 2 == 0 && dp > res {
            res = dp
        }
    }
    return res
}