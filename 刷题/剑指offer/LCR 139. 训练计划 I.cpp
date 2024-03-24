class Solution {
public:
    vector<int> trainingPlan(vector<int>& actions) {
        int slow = 0, fast = 0;
        int n = actions.size();
        while(fast < n) {
            if(actions[fast] & 1) {
                swap(actions[slow], actions[fast]);
                slow++;
            }
            fast++;
        }
        return actions;
    }
};