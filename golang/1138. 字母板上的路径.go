func alphabetBoardPath(target string) string {
    x,y:=0,0
    res:=[]byte{}
    for _,ch:=range []rune(target){
        tx:=int(ch-'a')/5
        ty:=int(ch-'a')%5
        if tx<x{
            for j:=0;j<x-tx;j++{
                res=append(res,'U')
            }
        }
        if ty<y {
            for j:=0;j<y-ty;j++{
                res=append(res,'L')
            }
        }
        if tx>x{
            for j:=0;j<tx-x;j++{
                res=append(res,'D')
            }
        }
        if ty>y {
            for j:=0;j<ty-y;j++{
                res=append(res,'R')
            }
        }
        res=append(res,'!')
        x,y=tx,ty
    }
    return string(res)
}