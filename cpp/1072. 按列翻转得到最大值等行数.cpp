class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> mp;
        int m=matrix.size(),n=matrix[0].size();
        for(int i=0;i<m;i++){
            string t=string(n, '0');
            for(int j=0;j<n;j++){
                t[j]='0'+(matrix[i][0]^matrix[i][j]);
            }
            mp[t]++;
        }
        int ans=0;
        for(auto &[k,v]:mp){
            ans=max(ans,v);
        }
        return ans;
    }
};