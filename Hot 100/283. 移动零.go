func moveZeroes(nums []int)  {
    n := len(nums)
    ind := 0
    cnt := 0
    for i:=0; i<n; i++ {
        if nums[i] != 0 {
            nums[ind]=nums[i]
            ind++
            cnt++
        }
    }
    for i:=cnt; i<n; i++ {
        nums[i]=0
    }
    return
}