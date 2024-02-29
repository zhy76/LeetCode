func getFolderNames(names []string) []string {
    ans:=make([]string,len(names))
    mp:=map[string]int{}
    for i,name:=range names{
        if mp[name]==0{
            mp[name]=1
            ans[i]=name
        }else{
            k:=mp[name]
            for mp[name+"("+strconv.Itoa(k)+")"]!=0{
                k++
            }
            mp[name]=k
            ans[i]=name+"("+strconv.Itoa(k)+")"
            mp[name+"("+strconv.Itoa(k)+")"]=1
        }
    }
    return ans
}