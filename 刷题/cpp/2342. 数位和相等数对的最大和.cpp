class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> mx(82);
        int ans=-1;
        for(int j=0;j<n;j++){
            int i=0;
            int x=nums[j];
            int s=0;
            while(x){
                s+=x%10;
                x=x/10;
            }
            if(mx[s]){
                ans=max(ans, mx[s]+nums[j]);
            }
            mx[s]=max(mx[s],nums[j]);
        }
        return ans;
    }
};