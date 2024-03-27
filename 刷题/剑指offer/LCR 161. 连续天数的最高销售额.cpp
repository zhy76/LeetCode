class Solution {
public:
    int maxSales(vector<int>& sales) {
        int n = sales.size();
        vector<int> dp(n, 0);
        dp[0] = sales[0];
        for(int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + sales[i], sales[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};  