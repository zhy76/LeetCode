func countBalls(lowLimit int, highLimit int) (ans int) {
    count:=map[int]int{}
    for i:=lowLimit;i<=highLimit;i++{
        sum:=0
        for x:=i;x>0;x/=10{
            sum+=x%10
        }
        count[sum]++
        ans=max(ans,count[sum])
    }
    return
}
func max(a,b int) int{
    if(a>b) {
        return a
    }
    return b
}