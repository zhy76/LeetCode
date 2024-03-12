class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        vector<int> dp(bamboo_len + 1, 0);
        for(int i = 2; i <= bamboo_len; i++) {
            int curMax = 0;
            for(int j = 1; j < i; j++) {
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }        
        return dp[bamboo_len];
    }
};

// 法二：数学，尽可能多分一些3
class Solution {
public:
    int cuttingBamboo(int bamboo_len) {
        if(bamboo_len <= 3) return bamboo_len - 1;
        int num = bamboo_len / 3;
        int yu = bamboo_len % 3;
        if(yu == 0) {
            return (int)pow(3, num);
        } else if(yu == 1) {
            return (int)pow(3, num - 1) * 4;
        } else {
            return (int)pow(3, num) * 2;
        }
    }
};