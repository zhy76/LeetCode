class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        int i=0,j=1;
        while(i<nums.size()&&j<nums.size()){
            if(nums[i]!=nums[j]){
                i++;
                j++;
                continue;
            }
            if(nums[i]==nums[j]){
                nums.erase(nums.begin()+j);
            }
        }
        return nums.size();
    }
};

// 法2：快慢指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int slow=0,fast=0;
        while(fast<nums.size()){
            if(nums[fast]!=nums[slow]){
                slow++;
                nums[slow]=nums[fast];
            }
            fast++;
        }
        return slow+1;
    }
};