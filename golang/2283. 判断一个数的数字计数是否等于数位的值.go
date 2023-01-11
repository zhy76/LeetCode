func digitCount(num string) bool {
    mp:=make(map[rune]int)
    for _,x:=range num{
        mp[x-'0']++
    }
    for i,x:=range num{
        if mp[rune(i)]==int(x-'0'){
            continue
        }else{
            return false
        }
    }
    return true
}