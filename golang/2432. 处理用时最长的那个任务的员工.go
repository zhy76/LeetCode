func hardestWorker(n int, logs [][]int) int {
    maxTime,t := 0,0
    ans := 0
    for i, log :=range logs {
        if i==0 {
            t=log[1]
        }else {
            t=logs[i][1]-logs[i-1][1]
        }
        if t>maxTime {
            maxTime=t
            ans=log[0]
        }else if t==maxTime {
            ans=min(ans,log[0])
        }
    }
    return ans
}
func min(x, y int) int{
    if x>y {
        return y
    }
    return x
}