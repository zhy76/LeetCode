class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int flag=1;
        vector<int> tmp;
        while(nums.size()>1){
            int n=nums.size();
            for(int i=0;i<n;i+=2){
                int t=0;
                if(flag==1){
                    t=min(nums[i],nums[i+1]);
                    flag*=-1;
                }else{
                    t=max(nums[i],nums[i+1]);
                    flag*=-1;
                }
                tmp.emplace_back(t);
            }
            nums=move(tmp);
        }
        return nums[0];
    }
};