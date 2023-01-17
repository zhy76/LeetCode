func countNicePairs(nums []int) int {
    h:=map[int]int{}
    ans:=0
    for _,x:=range nums{
        t,j:=x,0
        for ;t>0;t/=10{
            j=j*10+t%10
        }
        ans=(ans+h[x-j])%(1e9+7)
        h[x-j]++
    }
    return ans
}