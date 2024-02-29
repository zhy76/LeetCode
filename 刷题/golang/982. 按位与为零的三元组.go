func countTriplets(nums []int) int {
    st:=make(map[int]int)
    for _,x:=range nums{
        for _,y:=range nums{
            st[x&y]++
        }
    }
    cnt:=0
    for _,z:=range nums{
        for k,v:=range st {
            if(v==0) {
                continue
            }
            if(z&k==0){
                cnt+=v
            }
        }
    }
    return cnt
}