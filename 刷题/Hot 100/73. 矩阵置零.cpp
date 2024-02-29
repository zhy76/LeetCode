class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int> > mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    mp.push_back({i,j});
                }
            }
        }
        for(int k=0;k<mp.size();k++){
            for(int i=0;i<m;i++){
                matrix[i][mp[k][1]]=0;
            }
            for(int j=0;j<n;j++){
                matrix[mp[k][0]][j]=0;
            }
        }
    }
};