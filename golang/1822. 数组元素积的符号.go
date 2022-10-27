func arraySign(nums []int) int {
    sign:=1
    for _,x:=range nums{
        if x<0{
            sign=-sign
        }
        if x==0{
            return 0
        }
    }
    return sign
}