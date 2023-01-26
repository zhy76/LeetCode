class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<char> ans(n);
        int m=(k-n)/25;
        k-=26*m;
        for(int i=n-1;i>n-1-m;i--){
            ans[i]='z';
        }
        for(int i=0;i<=n-m-1;i++){
            if(i==n-m-1) ans[i]=k-(n-m)+'a';
            else ans[i]='a';
        }
        string res;
        for(int i=0;i<n;i++){
            res+=ans[i];
        }
        return res;
    }
};