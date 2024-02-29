class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);
        for(auto booking: bookings) {
            int start = booking[0];
            int end = booking[1];
            int k = booking[2];
            diff[start - 1] +=k;
            if(end < n) {
                diff[end] -= k;
            }
        }
        vector<int> ans(n, 0);
        ans[0] = diff[0];
        for(int i=1; i<n; i++) {
            ans[i] = ans[i-1] + diff[i];
        }
        return ans;
    }
};