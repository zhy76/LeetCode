class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0; 
        int minsum = 0;
        int n = gas.size();
        int start = 0;
        for(int i = 0; i < n; i++) {
            sum += (gas[i] - cost[i]);
            if(sum < minsum) {
                minsum = sum;
                start = (i + 1) % n;
            }
        }
        if(sum < 0) return -1;
        return start;
    }
};