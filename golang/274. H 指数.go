func hIndex(citations []int) int {
    n := len(citations)
    cnt := make([]int, n+1)
    for _, c := range citations {
        cnt[min(c, n)]++ // 引用次数 > n，等价于引用次数为 n
    }
    s := 0
    for i := n; ; i-- { // i=0 的时候，s>=i 一定成立
        s += cnt[i]
        if s >= i { // 说明有至少 i 篇论文的引用次数至少为 i
            return i
        }
    }
}

func min(a, b int) int { if b < a { return b }; return a }
