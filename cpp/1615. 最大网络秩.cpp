class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int> > grid(n, vector<int>(n));
        vector<int> cnt(n);
        for(int i=0;i<roads.size();i++){
            int x=roads[i][0];
            int y=roads[i][1];
            grid[x][y]=1;
            grid[y][x]=1;
            cnt[x]++;
            cnt[y]++;
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res=max(res,cnt[i]+cnt[j]-(grid[i][j]==1?1:0));
            }
        }         
        return res;
    }
};