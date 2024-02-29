class Solution {
public:
    int countAsterisks(string s) {
        int cnt=0;
        int ans=0;
        for(auto ch:s){
            if((cnt&1)==0&&ch=='*'){
                ans++;
            }
            if(ch=='|'){
                cnt++;
            }
        }
        return ans;
    }
};