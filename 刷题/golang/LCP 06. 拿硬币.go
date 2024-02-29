func minCount(coins []int) int {
    res:=0
    for _, coin := range coins {
        res+=(coin+1)/2
    }
    return res
}