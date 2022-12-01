func nearestValidPoint(x int, y int, points [][]int) (ans int) {
    ans=-1
    minD:=math.MaxInt32
    for i,point:=range points{
        if(point[0]==x||point[1]==y){
            d:=abs(x-point[0])+abs(y-point[1])
            if(d<minD){
                minD=d
                ans=i
            }
        }
    }
    return 
}
func abs(x int) int{
    if x<0 {
        return -x
    }else{
        return x
    }
}