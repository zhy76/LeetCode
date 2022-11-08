class Solution {
public:
    int ans=0;
    int dir[4][2]={{-1,0},{0,1},{0,-1},{1,0}};
    void bfs(int x,int y,vector<vector<char>> &grid,int m,int n){
        grid[x][y]='0';
        ans++;
        queue<pair<int,int>> qu;
        qu.push({x,y});
        while(!qu.empty()){
            auto [i,j]=qu.front();
            qu.pop();
            for(int k=0;k<4;k++){
                int tx=i+dir[k][0];
                int ty=j+dir[k][1];
                if(tx>=0&&tx<m&&ty>=0&&ty<n&&grid[tx][ty]=='1'){
                    grid[tx][ty]='0';
                    qu.push({tx,ty});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if (!m) return 0;
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    bfs(i,j,grid,m,n);
                }
            }
        }
        return ans;
    }
};