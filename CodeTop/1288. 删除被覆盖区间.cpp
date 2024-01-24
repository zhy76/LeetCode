class Solution {
public:
    struct cmp {
        bool operator ()(vector<int> x, vector<int> y) {
            if(x[0] != y[0]) {
                return x[0] < y[0];
            } else {
                return x[1] > y[1];
            }
        }
    };
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        int res = intervals.size();
        int left = intervals[0][0];
        int right = intervals[0][1];
        for(int i=1; i<intervals.size(); i++) {
            auto interval = intervals[i];
            if(left <= interval[0] && interval[1] <= right) {
                res--;
            } else {
                left = interval[0];
                right = interval[1];
            }
        }
        return res;
    }
};