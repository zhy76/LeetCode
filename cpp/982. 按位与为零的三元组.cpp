class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int cnt=0,n=nums.size();
        vector<int> st(1<<16);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                st[nums[i]&nums[j]]++;
            }
        }
        for(int i=0;i<(1<<16);i++){
            if(st[i]==0) continue;
            for(int k=0;k<n;k++){
                if((i&nums[k])==0){
                    cnt+=st[i];
                }
            }
        }
        return cnt;
    }
};
// 优化
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int> cnt(1 << 16);
        for (int x: nums) {
            for (int y: nums) {
                ++cnt[x & y];
            }
        }
        int ans = 0;
        for (int x: nums) {
            x = x ^ 0xffff;
            // 求x的子集
            for (int sub = x; sub; sub = (sub - 1) & x) {
                ans += cnt[sub];
            }
            ans += cnt[0];
        }
        return ans;
    }
};