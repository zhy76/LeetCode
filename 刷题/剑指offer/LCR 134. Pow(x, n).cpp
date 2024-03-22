class Solution {
public:
    double quick(double x, long long n) {
        double ans = 1;
        while(n) {
            if(n & 1) {
                ans = x * ans;
            }
            x *= x;
            n >>= 1;
        }
        return ans;
    }
    double myPow(double x, long long n) {
        if(n >= 0) return quick(x, n);
        else return 1.0 / quick(x, -n);
    }
};