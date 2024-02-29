class Solution {
public:
    int jump(vector<int>& nums) {
        int start=0;
        int end=1;
        int count=0;
        while(end<nums.size()){
            int maxnum=0;
            for(int j=start;j<end;j++){
                maxnum=max(maxnum, j+nums[j]);
            }   
            start=end;
            end=maxnum+1;
            count++;
        }
        return count;
    }
};