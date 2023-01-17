class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> h;
        int MOD=1e9+7;
        int res=0;
        for(int i:nums){
            int t=i,j=0;
            while(t){
                j=j*10+t%10;
                t/=10;
            }
            res=(res+h[j-i])%MOD;
            h[j-i]++;
        }
        return res;
    }
};