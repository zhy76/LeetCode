class Solution {
public:
    bool checkDynasty(vector<int>& places) {
        unordered_set<int> st;
        int minNum = INT_MAX;
        int maxNum = -1;
        for(auto place: places) {
            if(place == 0) continue;
            if(st.count(place)) return false;
            st.insert(place);
            minNum = min(minNum, place);
            maxNum = max(maxNum, place);
        }
        return maxNum - minNum <= 4;
    }
};