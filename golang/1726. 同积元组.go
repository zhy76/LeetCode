func tupleSameProduct(nums []int) int {
    mp := make(map[int]int)
    n := len(nums)
    for i:=0; i<n; i++ {
        for j:=i+1; j<n; j++ {
            mp[nums[i]*nums[j]]++
        }
    }
    ans := 0
    for _, v := range mp {
        ans += v*(v-1) * 4
    }
    return ans
}