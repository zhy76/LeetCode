func minOperations(boxes string) []int {
    left:=int(boxes[0]-'0')
    right:=0
    operation:=0
    n:=len(boxes)
    for i:=1;i<n;i++{
        if boxes[i]=='1'{
            right++
            operation+=i
        }
    }
    ans:=make([]int,n)
    ans[0]=operation
    for i:=1;i<n;i++{
        operation+=left-right
        if boxes[i]=='1'{
            left++
            right--
        }
        ans[i]=operation
    }
    return ans
}