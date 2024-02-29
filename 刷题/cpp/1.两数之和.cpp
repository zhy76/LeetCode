/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashTable;
        for(auto i=0;i<nums.size();i++){
            if(hashTable.find(target-nums[i])!=hashTable.end()){
                return {hashTable[target-nums[i]],i};
            }
            hashTable[nums[i]]=i;
        }
        return {};
    }
};
// @lc code=end

