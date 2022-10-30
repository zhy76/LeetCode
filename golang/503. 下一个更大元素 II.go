func nextGreaterElements(nums []int) []int {
    n:=len(nums)
    stack:=[]int{}
    ans:=make([]int,n)
    for i:=2*n-1;i>=0;i--{
        for len(stack)>0 && stack[len(stack)-1]<=nums[i%n]{
            stack=stack[:len(stack)-1]
        }
        if(len(stack)>0){
            ans[i%n]=stack[len(stack)-1]
        }else{
            ans[i%n]=-1
        }
        stack=append(stack,nums[i%n])
    }
    return ans
}