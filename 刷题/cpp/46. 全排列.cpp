class Solution {
private:
    vector<vector<int>> ans;
public:
    void dfs(vector<int>& nums,vector<int>& tmp,int ind,int n,unordered_map<int,bool> used){
        if(ind==n){
            ans.push_back(tmp);
            return;
        }
        for(int i=0;i<n;i++){
            if(!used[nums[i]]){
                tmp.push_back(nums[i]);
                used[nums[i]]=true;
                dfs(nums,tmp,ind+1,n,used);
                tmp.pop_back();
                used[nums[i]]=false;
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,bool> used;
        vector<int> tmp;
        dfs(nums,tmp,0,n,used);
        return ans;
    }
};