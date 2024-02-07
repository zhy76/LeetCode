class Solution {
public:
    vector<int> sockCollocation(vector<int>& sockets) {
        int sum = 0;
        for(auto socket : sockets) {
            sum ^= socket;
        }
        int m = 1;
        while((m & sum) == 0) {
            m <<= 1;
        }

        int a = 0;
        int b = 0;
        for(auto socket : sockets) {
            if(m & socket) a ^= socket;
            else b ^= socket; 
        }
        return vector<int>{a,b};
    }
};