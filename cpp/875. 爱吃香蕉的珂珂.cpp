class Solution {
public:
    long long f(vector<int>& piles, int x) {
        long long hour = 0;
        for(int pile: piles) {
            hour += pile/x;
            if(pile % x!=0) {
                hour+=1;
            }
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9 + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(f(piles, mid) <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};