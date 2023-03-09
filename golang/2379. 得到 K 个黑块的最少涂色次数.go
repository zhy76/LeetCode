func minimumRecolors(blocks string, k int) int {
    i, j := 0, k - 1
    res := len(blocks)
    for j < len(blocks) {
        cnt := 0
        for h := i; h <= j; h++ {
            if blocks[h] == 'B' {
                cnt++
            }
        }
        
        res=min(res, k-cnt)
        i++
        j++
    }
    return res
}
func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}