func interpret(command string) string {
    res := &strings.Builder{}
    for i,c:=range command{
        if c== 'G'{
            res.WriteByte('G')
        }else if c=='('{
            if command[i+1]==')'{
                res.WriteByte('o')
            }else{
                res.WriteString("al")
            }
        }
    }
    return res.String()
}