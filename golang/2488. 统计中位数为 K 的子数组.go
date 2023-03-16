func countSubarrays(nums []int, k int) (res int) {
    n := len(nums)
    ind := -1
    count := make(map[int]int, n+1)
    count[0] = 1
    for i, num := range nums {
        if num == k {
            ind = i
        }
    } 
    sum := 0
    for i, num := range nums {
        if num > k {
            num = 1
        } else if num < k {
            num = -1
        } else if num == k {
            num = 0
        }
        sum += num
        if i < ind {
            count[sum]++
        } else {
            res += count[sum] + count[sum-1]
        }
    }
    return
}