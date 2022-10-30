class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
       int n=arr.size();
       vector<int> st;
       vector<int> left(n),right(n);
       for(int i=0;i<n;i++){
           while(!st.empty()&&arr[i]<=arr[st.back()]){
               st.pop_back();
           }
           left[i]=i-(st.empty()?-1:st.back());
           st.emplace_back(i);
       }
       for(int i=n-1;i>=0;i--){
           while(!st.empty()&&arr[i]<arr[st.back()]){
               st.pop_back();
           }
           right[i]=(st.empty()?n:st.back())-i;
           st.emplace_back(i);
       }
       long long ans=0;
       long long mod=1e9+7;
       for(int i=0;i<n;i++){
           ans=(ans+(long long)left[i]*right[i]*arr[i])%mod;
       }
       return ans;
    }
};
