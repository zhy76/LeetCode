class Solution {
private:
    int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
    bool flag=false;
    bool vis[10][10]={false};
public:
    bool check(int x,int y,int m, int n){
        if(x<0||x>=m||y<0||y>=n||vis[x][y]){
            return false;
        }
        return true;
    }
    void dfs(vector<vector<char>>& board,string word,int x,int y,int ind){
        
        if(word[ind]!=board[x][y]){
            return;
        }

        if(ind==word.size()-1){
            flag=true;
            return;
        }
        for(int d=0;d<4;d++){
            int tx=x+dir[d][0];
            int ty=y+dir[d][1];
            if(check(tx,ty,board.size(),board[0].size())){
                vis[tx][ty]=true;
                dfs(board,word,tx,ty,ind+1);
                vis[tx][ty]=false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=true;
                dfs(board,word,i,j,0);
                vis[i][j]=false;
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }
};