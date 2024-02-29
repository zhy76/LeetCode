func countMatches(items [][]string, ruleKey string, ruleValue string) int {
    var d=map[string]int{"type":0,"color":1,"name":2}
    ans:=0
    ind:=d[ruleKey]
    for _,item:=range items{
        if item[ind]==ruleValue {
            ans++
        }
    }
    return ans
}