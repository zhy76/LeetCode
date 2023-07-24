class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelsSet;
        int ans=0;
        int n=jewels.length(),m=stones.length();
        for(int i=0;i<n;i++){
            jewelsSet.insert(jewels[i]);
        }
        for(int i=0;i<m;i++){
            if(jewelsSet.count(stones[i])){
                ans++;
            }
        }
        return ans;
    }
};