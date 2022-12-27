class Solution {
public:
    int minimumMoves(string s) {
        int n=s.length();
        int i=0;
        int cnt=0;
        while(i<n){
            if(s[i]=='O'){
                i++;
                continue;
            }
            int t=0;
            while(i<n&&t<3){
                s[i]='O';
                t++;
                i++;
            }
            cnt++;
        }
        return cnt;
    }
};