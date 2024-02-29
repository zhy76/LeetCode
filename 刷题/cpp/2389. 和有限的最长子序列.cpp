class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m=nums.size(),n=queries.size();
        sort(nums.begin(),nums.end());
        vector<int> ans(n);
        vector<int> f(m+1);
        for(int i=0;i<m;i++){
            f[i+1]=f[i]+nums[i];
        }
        for(int i=0;i<n;i++){
            ans[i]=upper_bound(f.begin(),f.end(),queries[i])-f.begin()-1;
        }
        return ans;
    }
};