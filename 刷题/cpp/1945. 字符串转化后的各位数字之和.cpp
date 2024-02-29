class Solution {
public:
    int getLucky(string s, int k) {
        int sum=0;
        for(auto &ch:s){
            int t=ch-'a'+1;  
            while(t){
                sum+=t%10;
                t/=10;
            }
        }
        k--;
        int ans=sum;
        while(k--){
            ans=0;
            while(sum){
                ans+=sum%10;
                sum/=10;
            }
            sum=ans;
        }
        return ans;
    }
};