class Solution {
public:
    int countHomogenous(string s) {
        const int MOD=1e9+7;
        char pre=s[0];
        long long cnt=0;
        long long ans=0;
        for(auto ch:s){
            if(ch==pre){
                cnt++;
            }else{
                ans+=((1+cnt)%MOD*cnt%MOD/2)%MOD;
                cnt=1;
                pre=ch;
            }
        }
        ans+=(long long)(1+cnt)*cnt/2;
        return ans%MOD;
    }
};