func minSubarray(nums []int, p int) int {
    n := len(nums)
    s := make([]int, n+1)
    for i, v := range nums {
        s[i+1] = (s[i] + v) % p
    }
    x := s[n]
    if x == 0 {
        return 0 // 移除空子数组（这个 if 可以不要）
    }

    ans := n
    last := map[int]int{}
    for i, v := range s {
        last[v] = i
        if j, ok := last[(v-x+p)%p]; ok {
            ans = min(ans, i-j)
        }
    }
    if ans < n {
        return ans
    }
    return -1
}

func min(a, b int) int { if b < a { return b }; return a }