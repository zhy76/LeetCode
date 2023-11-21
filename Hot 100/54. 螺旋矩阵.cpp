class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int dir[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
        int i=0,j=0,d=0;
        vector<vector<bool> > visit(m, vector<bool>(n,false));
        vector<int> ans;
        while(i>=0 && i<m && j>=0 && j<n && !visit[i][j]){
            visit[i][j]=true;
            ans.push_back(matrix[i][j]);
            int x=i+dir[d][0];
            int y=j+dir[d][1];
            if(x<0 || x>=m || y<0 || y>=n) {
                d=(d+1)%4;
                i+=dir[d][0];
                j+=dir[d][1];
                continue;
            } else if(visit[x][y]){
                d=(d+1)%4;
                i+=dir[d][0];
                j+=dir[d][1];
                continue;
            }
            i=x;
            j=y;
        }
        return ans;
    }
};