func rearrangeCharacters(s string, target string) int {
    var sCnt,targetCnt [26]int
    for _,c:=range s{
        sCnt[c-'a']++
    }
    for _,c:=range target{
        targetCnt[c-'a']++
    }
    ans:=len(s)
    for i,c:=range targetCnt{
        if c>0{
            ans=min(ans,sCnt[i]/c)
        }
        
        if ans==0{
            return 0
        }
    }
    return ans
}
func min(a,b int) int{
    if a<b{
        return a
    }
    return b
}