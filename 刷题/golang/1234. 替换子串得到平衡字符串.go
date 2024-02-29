func balancedString(s string) int {
    cnt:=map[byte]int{}
    for _,x:=range s{
        cnt[byte(x)]++
    }
    t:=len(s)/4
    check:=func() bool{
        if cnt['Q'] > t ||
            cnt['W'] > t ||
            cnt['E'] > t ||
            cnt['R'] > t {
            return false
        }
        return true
    }
    if check() {
        return 0
    }
    ans:=len(s)
    for l,r:=0,0;l<len(s);l++{
        for r<len(s)&&!check(){
            cnt[s[r]]--
            r++
        }
        if !check(){
            break
        }
        ans=min(ans,r-l)
        cnt[s[l]]++
    }
    return ans
}
func min(x,y int) int {
    if x>y {
        return y
    }
    return x
}