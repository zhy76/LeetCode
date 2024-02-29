class Solution {
public:
    // 天数和载重量的关系为单调递减
    int f(vector<int>& weights, int x) {
        int days = 1;
        int tmp = 0;
        for(auto weight:weights) {
            tmp += weight;
            if(tmp > x) {
                days+=1;
                tmp = weight;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()), right = 500 * 5 * 1e4 + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(f(weights, mid) <= days) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};