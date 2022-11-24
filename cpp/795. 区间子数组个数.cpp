//一次遍历
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ind1=-1,ind2=-1;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>right) ind2=i;
            if(nums[i]>=left) ind1=i;
            ans+=(ind1-ind2);
        }
        return ans;
    }
};
//计数
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return count(nums,right)-count(nums,left-1);
    }
    int count(vector<int>& nums,int lower){
        int res=0,cur=0;
        for(auto x:nums){
            cur=x<=lower?cur+1:0;
            res+=cur;            
        }
        return res;
    }
};