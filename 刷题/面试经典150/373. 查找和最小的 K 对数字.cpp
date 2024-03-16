class Solution {
public:
    struct cmp{
        bool operator ()(const vector<int>& a, const vector<int>& b) {
            return a[0] + a[1] > b[0] + b[1];
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> qu;
        for(int i = 0; i < nums1.size(); i++) {
            qu.push({nums1[i], nums2[0], 0});
        }
        vector<vector<int>> res;
        while(!qu.empty() && k > 0) {
            auto cur = qu.top();
            qu.pop();
            int next = cur[2] + 1;
            res.push_back({cur[0], cur[1]});
            k--;
            if(next< nums2.size()) {
                qu.push({cur[0], nums2[next], next});
            }
        }
        return res;
    }
};