/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
public:
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    queue<pair<int,int>> qu;
    void dfs(int x,int y,vector<vector<int>>& grid,int n){
            grid[x][y]=2;
            qu.emplace(x,y);
            for(int i=0;i<4;i++){
                int tx=dir[i][0]+x;
                int ty=dir[i][1]+y;
                if(tx>=0&&tx<n&&ty>=0&&ty<n&&grid[tx][ty]==1){
                    dfs(tx,ty,grid,n);
                }
            }
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,n);
                    int step=0;
                    while(!qu.empty()){
                        int qz=qu.size();
                        for(int i=0;i<qz;i++){
                            auto [x,y]=qu.front();
                            qu.pop();
                            for(int j=0;j<4;j++){
                                int tx=dir[j][0]+x;
                                int ty=dir[j][1]+y;
                                if(tx>=0&&tx<n&&ty>=0&&ty<n){
                                    if(grid[tx][ty]==0){
                                        qu.emplace(tx,ty);
                                        grid[tx][ty]=-1;
                                    }else if(grid[tx][ty]==1){
                                        return step;
                                    }
                                    
                                }
                            }
                        }
                        step++;
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

