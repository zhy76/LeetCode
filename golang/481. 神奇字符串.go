func magicalString(n int) int {
    if n<4{
        return 1
    }
    s:=make([]byte,n)
    copy(s,"122")
    res:=1
    i,j:=2,3
    for j<n{
        size:=s[i]-'0'
        num:=3-(s[j-1]-'0')
        for size>0&&j<n{
            s[j]='0'+num
            if num==1{
                res++
            }
            j++
            size--
        }
        i++
    }
    return res
}