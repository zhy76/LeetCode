func nextPermutation(nums []int)  {
    i := len(nums)-2
    for i >= 0 && nums[i] >= nums[i+1] {
        i--
    }
    if i >= 0 {
        j:= len(nums)-1 
        for j >= 0 && nums[j] <= nums[i] {
            j--
        }
        nums[i], nums[j] = nums[j], nums[i]
    }
    reverse(nums[i+1:])
}
func reverse(nums []int) {
    for i, n:=0, len(nums); i < n / 2; i++ {
        nums[i], nums[n-1-i] = nums[n-1-i], nums[i]
    }
}