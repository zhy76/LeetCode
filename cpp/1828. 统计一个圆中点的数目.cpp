class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n=queries.size(),m=points.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                int cx=queries[i][0]-points[j][0],cy=queries[i][1]-points[j][1],r=queries[i][2];
                if(cx*cx+cy*cy<=r*r){
                    cnt++;
                }
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }
};