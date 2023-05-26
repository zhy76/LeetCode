class Solution {
public:
    struct Point{
        int x;
        int y;
        int step;
    };
    int dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    bool check(int x,int y,int m,int n){
        if(x>=0&&x<m&&y>=0&&y<n){
            return true;
        }
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<Point> qu;
        if(grid[0][0]==1){
            return -1;
        }
        qu.push(Point{0,0,0});
        vector<vector<int> > inq(m,vector<int>(n));
        inq[0][0]=1;
        while(!qu.empty()){
            Point now=qu.front();
            qu.pop();
            if(now.x==m-1&&now.y==n-1){
                return now.step+1;
            }
            for(int i=0;i<8;i++){
                int tx=dir[i][0]+now.x;
                int ty=dir[i][1]+now.y;
                if(check(tx,ty,m,n)&&inq[tx][ty]==0&&grid[tx][ty]==0){
                    qu.push(Point{tx,ty,now.step+1});
                    inq[tx][ty]=1;
                }
            }
        }
        return -1;
    }
};