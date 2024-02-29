class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int r=rowSum.size(),c=colSum.size();
        vector<vector<int> > grid(r,vector<int>(c,0));
        int i=0,j=0;
        while(i<r&&j<c){
                int x=min(rowSum[i],colSum[j]);
                grid[i][j]=x;
                rowSum[i]-=x;
                colSum[j]-=x;
                if(rowSum[i]==0){
                    i++;
                }
                if(colSum[j]==0){
                    j++;
                }
        }
        return grid;
    }
};