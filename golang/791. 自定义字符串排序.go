func customSortString(order, s string) string {
    fre:=[26]int{}
    for _,c:=range s{
        fre[c-'a']++
    }
    t:=&strings.Builder{}
    for _,c:=range order{
        if fre[c-'a']>0{
            t.WriteString(strings.Repeat(string(c),fre[c-'a']))
            fre[c-'a']=0
        }
    }
    for i,k :=range fre{
        if k>0{
            t.WriteString(strings.Repeat(string('a'+i),k))
        }
    }
    return t.String()
}