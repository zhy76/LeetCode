func alertNames(keyName []string, keyTime []string) (ans []string) {
    timeMap:=make(map[string][]int)
    for i,name:=range keyName{
        time:=keyTime[i]
        hour:=int(time[0]-'0')*10+int(time[1]-'0')
        minute:=int(time[3]-'0')*10+int(time[4]-'0')
        timeMap[name]=append(timeMap[name],hour*60+minute)
    }
    for name,vec:=range timeMap{
        sort.Ints(vec)
        for i,t:=range vec[2:]{
            diff:=t-vec[i]
            if diff<=60{
                ans=append(ans,name)
                break
            }
        }
    }
    sort.Strings(ans)
    return
}