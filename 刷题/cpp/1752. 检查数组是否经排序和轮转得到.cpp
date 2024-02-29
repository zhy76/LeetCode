class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=1,len=nums.size();
        for(int i=0;i<2*len;i++){
            if(i>0){
                if(nums[i%len]>=nums[(i-1)%len]) cnt++;
                else if(cnt==len){
                    return true;
                } else{
                    cnt=1;
                }
            }
        }
        if(cnt==2*len) return true;
        return false;
    }
};