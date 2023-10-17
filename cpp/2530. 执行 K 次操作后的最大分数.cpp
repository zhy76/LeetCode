class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> qu(nums.begin(), nums.end());
        long long ans=0;
        for(int i=0;i<k;i++){
            int t=qu.top();
            qu.pop();
            ans+=t;
            qu.push(ceil(t*1.0/3));
        }
        return ans;
    }
};