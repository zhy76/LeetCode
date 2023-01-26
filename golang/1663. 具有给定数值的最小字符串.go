func getSmallestString(n int, k int) string {
    s:=[]byte{}
    for i:=1;i<=n;i++{
        lower:=max(1,k-(n-i)*26)
        k-=lower
        s=append(s,'a'+byte(lower)-1)
    }
    return string(s)
}
func max(x,y int) int {
    if x>y {
        return x
    }
    return y
}