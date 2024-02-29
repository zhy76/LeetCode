class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ans;
        sort(intervals.begin(),intervals.end());
        int left=0,right=0;
        for(int i=0;i<intervals.size();i++){
            left=intervals[i][0];
            right=intervals[i][1];
            if (ans.size()==0 || ans.back()[1]<left){
                ans.push_back({left,right});
            }else{
                right=max(right,ans.back()[1]);
                ans.back()[1]=right;
            }
        }
        return ans;
    }
};