class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int first=0;first<n;first++){
            if(first>0&&nums[first]==nums[first-1]) continue;
            int target=-nums[first];
            int thrid=n-1;
            for(int second=first+1;second<n;second++){
                if(second>first+1&&nums[second]==nums[second-1]) continue;
                while(second<thrid&&nums[second]+nums[thrid]>target){
                    thrid--;
                }
                if(second==thrid) break;
                if(nums[second]+nums[thrid]==target){
                    ans.push_back({nums[first],nums[second],nums[thrid]});
                }
            }
        }
        return ans;
    }
};