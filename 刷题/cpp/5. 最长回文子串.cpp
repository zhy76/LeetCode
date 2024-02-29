// 法一：动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int maxL=1,begin=0;
        if(n<2){
            return s;
        }
        vector<vector<bool> > dp(n,vector<bool>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i<n;i++){
                int j=i+l-1;
                if(j>=n){
                    break;
                }
                if(s[i]!=s[j]){
                    dp[i][j]=false;
                }else{
                    if(l<3){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j]&&l>maxL){
                    maxL=l;
                    begin=i;
                }
            }
        }
        return s.substr(begin,maxL);
    }
};
// 法二：中心扩散
class Solution {
public:
    pair<int,int> expand(string s,int left,int right){
        while(left>=0&&right<s.length()&&s[left]==s[right]){
            left--;
            right++;
        }
        return {left+1,right-1};
    }
    string longestPalindrome(string s) {
        int start=0,end=0;
        for(int i=0;i<s.length();i++){
            auto [left1,right1]=expand(s,i,i);
            auto [left2,right2]=expand(s,i,i+1);
            if(right1-left1>end-start){
                end=right1;
                start=left1;
            }
            if(right2-left2>end-start){
                end=right2;
                start=left2;
            }
        }
        return s.substr(start,end-start+1);
    }
};