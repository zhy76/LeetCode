class Solution {
private:
    vector<vector<int>> ans;
    bool vis[20];
public:
    void dfs(int ind,vector<int>& nums,vector<int> tmp){
        if(ind==nums.size()){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(nums[ind]);
        dfs(ind+1,nums,tmp);
        tmp.pop_back();
        dfs(ind+1,nums,tmp);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        dfs(0,nums,tmp);
        return ans;
    }
};