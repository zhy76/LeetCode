class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxD=0;
        for(int i=0;i<nums.size();i++){
            if(i<=maxD){
                maxD=max(maxD,i+nums[i]);
                if(maxD>=nums.size()-1) return true;
            }
        }
        return false;
    }
};