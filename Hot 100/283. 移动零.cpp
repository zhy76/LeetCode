class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int ind=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[ind]=nums[i];
                ind++;
                cnt++;
            }
        }
        for(int i=cnt;i<n;i++){
            nums[i]=0;
        }
        return;
    }
};