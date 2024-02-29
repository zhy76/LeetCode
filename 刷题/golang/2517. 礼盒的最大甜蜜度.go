func maximumTastiness(price []int, k int) int {
    sort.Ints(price)
    left,right:=0,price[len(price)-1]-price[0]
    for left<right {
        mid:=(left+right+1)/2
        if(check(price,k,mid)){
            left=mid
        }else {
            right=mid-1
        }
    }
    return left
}
func check(price []int,k int,tastiness int) bool {
    prev:=int(math.Inf(-1)) >>1
    cnt:=0
    for _,p:=range price {
        if p-prev>=tastiness {
            cnt++
            prev=p
        }
    }
    return cnt>=k
}