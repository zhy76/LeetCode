class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> count;
        int res=0;
        for(auto &t: time){
            res+=count[((60-t%60)%60)];
            count[t%60]++;
        }
        return res;
    }
};