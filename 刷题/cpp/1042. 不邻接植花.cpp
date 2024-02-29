class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int> > g(n);
        for(auto path:paths){
            int x=path[0]-1,y=path[1]-1;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> answer(n);
        for(int i=0;i<n;i++){
            vector<bool> colored(5, false);
            for(auto &v:g[i]){
                colored[answer[v]]=true;
            }
            for(int j=1;j<=4;j++){
                if(!colored[j]){
                    answer[i]=j;
                    break;
                }
            }
        }
        return answer;
    }
};