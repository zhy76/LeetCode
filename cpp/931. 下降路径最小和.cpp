class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // f[i][j]=min(f[i-1][j-1],f[i-1][j],f[i-1][j+1])+matrix[i][j];
        // min(f[n-1][0],f[n-1][1],...)
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int> > f(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            f[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int tmin=0x3fffffff;
                if(j-1>=0){
                    tmin=min(tmin,f[i-1][j-1]);
                }
                tmin=min(tmin,f[i-1][j]);
                if(j+1<m){
                    tmin=min(tmin,f[i-1][j+1]);
                }
                f[i][j]=tmin+matrix[i][j];
            }
        }
        int ans=f[n-1][0];
        for(int i=0;i<m;i++){
            ans=min(ans,f[n-1][i]);
        }
        return ans;
    }
};