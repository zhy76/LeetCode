class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n=sequence.size(),m=word.size();
        if(n<m) return 0;
        vector<int> dp(n);
        for(int i=m-1;i<n;i++){
            bool valid=true;
            for(int j=0;j<m;j++){
                if(sequence[i-m+1+j]!=word[j]){
                    valid=false;
                    break;
                }
            }
            if(valid){
                dp[i]=(i==m-1?0:dp[i-m])+1;
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
