class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int ans=0;
        for(auto &[k, v]: mp){
            ans+=(v-1)*v*4;
        }
        return ans;
    }
};