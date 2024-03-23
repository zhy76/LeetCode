class Solution {
public:
    bool check(vector<int>& citations, int x) {
        int res = 0;
        for(auto c:citations) {
            if(c >= x) {
                res++;
            }
        }
        return res >= x;
    }
    int hIndex(vector<int>& citations) {
        int n= citations.size();
        int l = 0, r = n;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(check(citations, mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};