class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 1, p3 = 1, p5 = 1;
        vector<int> ugly(n + 1, 0);
        ugly[1] = 1;
        int p = 2;
        while(p <= n) {
            int x = min(ugly[p2]*2, min(ugly[p3]*3, ugly[p5]*5));
            ugly[p++] = x;
            if(x == ugly[p2] * 2) {
                p2++;
            }
            if(x == ugly[p3] * 3) {
                p3++;
            }
            if(x == ugly[p5] * 5) {
                p5++;
            }
        }
        return ugly[n];
    }
};