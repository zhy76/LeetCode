func threeSum(nums []int) [][]int {
    n:=len(nums)
    sort.Ints(nums)
    ans:=make([][]int,0)
    for first:=0;first<n;first++{
        if first>0&&nums[first]==nums[first-1]{
            continue
        }
        thrid:=n-1
        target:=-nums[first]
        for second:=first+1;second<n;second++{
            if second>first+1&&nums[second]==nums[second-1]{
                continue
            }
            for second<thrid&&nums[second]+nums[thrid]>target{
                thrid--
            }
            if second==thrid{
                break
            }
            if nums[second]+nums[thrid]==target{
                ans=append(ans,[]int{nums[first],nums[second],nums[thrid]})
            }
        }
    }
    return ans
}