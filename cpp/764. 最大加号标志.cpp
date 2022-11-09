class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> dp(n,vector(n,n));
        unordered_set<int> st;
        for(auto &&v: mines){
            st.emplace(v[0]*n+v[1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(st.count(i*n+j)){
                    count=0;
                }else{
                    count++;
                }
                dp[i][j]=min(dp[i][j],count);
            }
            count =0;
            for(int j=n-1;j>=0;j--){
                if(st.count(i*n+j)){
                    count=0;
                }else{
                    count++;
                }
                dp[i][j] = min(dp[i][j], count);
            }
        }
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(st.count(j*n+i)){
                    count=0;
                }else{
                    count++;
                }
                dp[j][i]=min(dp[j][i],count);
            }
            count=0;
            for(int j=n-1;j>=0;j--){
                if(st.count(j*n+i)){
                    count=0;
                }else{
                    count++;
                }
                dp[j][i]=min(dp[j][i],count);
                ans = max(ans, dp[j][i]);
            }
        }
        return ans;
    }
};