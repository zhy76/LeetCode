class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        int m = firstList.size(), n = secondList.size();
        vector<vector<int> > res;
        while(i<m && j<n) {
            int a1 = firstList[i][0], a2 = firstList[i][1];
            int b1 = secondList[j][0], b2 = secondList[j][1];
            if(a2 >= b1 && b2 >= a1) {
                int left = max(a1, b1);
                int right = min(a2, b2);
                res.push_back({left, right});
            }
            if(b2 < a2) {
                j++;
            } else i++; 
        }
        return res;
    }
};