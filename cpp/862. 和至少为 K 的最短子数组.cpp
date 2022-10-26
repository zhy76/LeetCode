class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> qu;
        int n=nums.size();
        long s[n+1];
        for(int i=0;i<n;i++){
            s[i+1]=s[i]+nums[i];
        }
        int ans=n+1;
        for(int i=0;i<=n;i++){
            long curnum=s[i];
            while(!qu.empty()&&curnum-s[qu.front()]>=k){
                ans=min(ans,i-qu.front());
                qu.pop_front();
            }
            while(!qu.empty()&&s[qu.back()]>=curnum){
                qu.pop_back();
            }
            qu.push_back(i);
        }
        return ans==n+1?-1:ans;
    }
};
