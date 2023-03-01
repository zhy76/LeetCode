class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int> > ans(n-2,vector<int>(n-2,0));
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                for(int k=i;k<i+3;k++){
                    for(int h=j;h<j+3;h++){
                        ans[i][j]=max(ans[i][j],grid[k][h]);
                    }
                }
            }
        }
        return ans;
    }
};