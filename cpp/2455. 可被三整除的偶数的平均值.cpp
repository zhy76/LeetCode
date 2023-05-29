class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum=0, cnt=0;
        for(auto num:nums){
            if (num % 6 == 0) {
                sum+=num;
                cnt++;
            }
        }
        if (cnt==0) return 0;
        return sum/cnt;
    }
};