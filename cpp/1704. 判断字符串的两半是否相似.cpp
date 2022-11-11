class Solution {
public:
    int Count(string s){
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                cnt++;
            }
        }
        return cnt;
    }
    bool halvesAreAlike(string s) {
        int n=s.length();
        int cnt1=0,cnt2=0;
        string s1=s.substr(0,n/2);
        string s2=s.substr(n/2,n/2);
        cnt1=Count(s1);
        cnt2=Count(s2);
        if(cnt1==cnt2) return true;
        return false;
    }
};