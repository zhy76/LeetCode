class Solution {
public:
    bool check(int y,vector<int>& nums,int maxOperations){
        int op=0;
        for(auto &num:nums){
            op+=(num-1)/y;
        }
        if(op<=maxOperations) return true;
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left=1,right=*max_element(nums.begin(),nums.end());
        while(left<right){
            int mid=left+(right-left)/2;
            if(check(mid,nums,maxOperations)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};