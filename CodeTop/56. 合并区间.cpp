class Solution {
public:
    struct cmp {
        bool operator ()(vector<int> x, vector<int> y) {
            return x[0] < y[0];
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        vector<vector<int> > res;
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++) {
            auto interval = intervals[i];
            int left = res.back()[0];
            int right = res.back()[1];
            if(interval[0] > right) {
                res.push_back(interval);
            } else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
                res.back()[0] = left;
                res.back()[1] = right;
            }
        }
        return res;
    }
};