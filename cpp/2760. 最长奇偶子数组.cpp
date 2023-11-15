class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        bool flag=false;
        int ans=0,cnt=0;
        int l=0;
        for(int i=0;i<nums.size();i++){
            if(!flag){
                if(nums[i]%2 == 0 && nums[i]<=threshold){
                    flag=true;
                    cnt++;
                    l=i;
                }
            } else if(flag){
                if(i-1>=l && nums[i]%2!=nums[i-1]%2 && nums[i]<=threshold){
                    cnt++;
                    cout<<cnt<<endl;
                } else{
                    ans=max(ans,cnt);
                    if(nums[i]%2 != 0 || nums[i] > threshold){
                        flag=false;
                        cnt=0;
                    } else cnt=1;
                    
                }
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
};