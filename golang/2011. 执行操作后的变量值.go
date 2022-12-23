func finalValueAfterOperations(operations []string) int {
    ans:=0
    for _,x:=range operations{
        if(x[0]=='+'||x[2]=='+') {
            ans++
        }
        if(x[0]=='-'||x[2]=='-') {
            ans--
        }
    }
    return ans
}