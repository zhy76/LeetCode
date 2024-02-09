class Solution {
public:
    struct cmp {
        bool operator()(const vector<long>& a, const vector<long>& b) {
            return a[0] > b[0];
        }
    };
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<vector<long>, vector<vector<long>>, cmp> qu;
        vector<long> ugly(n+1, 0);
        ugly[1] = 1;
        int p = 2;
        for(auto prime : primes) {
            // 当前节点值， 当前素数，当前指针
            qu.push({prime, prime, 1});
        }
        while(p <= n) {
            auto cur = qu.top();
            int value = cur[0];
            int prime = cur[1];
            int ind = cur[2];
            qu.pop();
            if(value != ugly[p-1]) {
                ugly[p] = value;
                // cout<<p<<" "<<ugly[p]<<endl;
                p++;
            }
            qu.push({ugly[ind]*prime, prime, ind+1});
        }
        return ugly[n];
    }
};