func groupAnagrams(strs []string) [][]string {
    mp:=map[[26]int][]string{}
    for _,str:= range strs {
        count:=[26]int{}
        for _,ch:= range str {
            count[ch-'a']++
        }
        mp[count]=append(mp[count],str)
    }
    ans:=make([][]string,0)
    for _,v:=range mp {
        ans=append(ans,v)
    }
    return ans
}