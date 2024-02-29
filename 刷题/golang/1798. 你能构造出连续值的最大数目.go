func getMaximumConsecutive(coins []int) int {
    x:=0
    sort.Ints(coins)
    for _,coin:=range coins{
        if coin>x+1{
            break
        }
        x+=coin
    }
    return x+1
}