class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int> > row(n,vector<int>(m+1));
        vector<vector<int> > col(m,vector<int>(n+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i][j+1]=row[i][j]+grid[i][j];
                col[j][i+1]=col[j][i]+grid[i][j];
            }
        }
        for(int d=min(m,n);d>0;d--){
            for(int i=0;i<=n-d;i++){
                for(int j=0;j<=m-d;j++){
                    if(row[i][j+d]-row[i][j]==d&&
                       row[i+d-1][j+d]-row[i+d-1][j]==d&&
                       col[j][i+d]-col[j][i]==d&&
                       col[j+d-1][i+d]-col[j+d-1][i]==d){
                           return d*d;
                       }
                }
            }
        }
        return 0;
    }
};