class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
       int diff=0;
       int m=nums1.size(),n=nums2.size();
       if(6*m<n||6*n<m) return -1;
       diff=accumulate(nums1.begin(),nums1.end(),0)-accumulate(nums2.begin(),nums2.end(),0);
       if(diff<0){
           diff=-diff;
           swap(nums1,nums2);
       }
       vector<int> cnt(6,0);
       for(auto x:nums1) cnt[x-1]++;
       for(auto x:nums2) cnt[6-x]++;
       int ans=0;
       for(int i=5;i>0;i--){
           if(i*cnt[i]>=diff){
               return ans+(diff+i-1)/i;
           }
           diff-=i*cnt[i];
           ans+=cnt[i];
       }
       return ans;
    }
};