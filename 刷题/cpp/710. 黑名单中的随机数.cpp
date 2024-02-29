class Solution {
public:
    unordered_map<int,int> mapping;
    int sz;
    Solution(int n, vector<int>& blacklist) {
        sz = n - blacklist.size();
        for(auto balck:blacklist) {
            mapping[balck] = 666;
        }
        int last = n-1;
        for(auto balck:blacklist) {
            if(balck >=sz) {
                continue;
            }
            while(mapping.count(last)) {
                last--;
            }
            mapping[balck] = last;
            last--;
        }
    }
    
    int pick() {
        int ind = rand()%sz;
        if(mapping.count(ind)) {
            return mapping[ind];
        }
        return ind;
    }   
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */