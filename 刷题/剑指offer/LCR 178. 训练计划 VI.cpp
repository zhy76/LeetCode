class Solution {
public:
    int trainingPlan(vector<int>& actions) {
        vector<int> ans(32, 0);
        for(auto action : actions) {
            for(int i = 0; i < 32; i++) {
                if(action & (1 << i)) ans[i]++;
            }
        }
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res |= (ans[i] % 3) << i;
        }
        return res;
    }
};