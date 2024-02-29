class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int maxTime=0;
        int result=0;
        int t=0;
        for(int i=0;i<logs.size();i++){
            if(i==0) t=logs[i][1];
            else t=logs[i][1]-logs[i-1][1];
            if (t>maxTime){
                maxTime=t;
                result=logs[i][0];
            }else if (t==maxTime){
                result=min(result,logs[i][0]);
            }
        }
        return result;
    }
};