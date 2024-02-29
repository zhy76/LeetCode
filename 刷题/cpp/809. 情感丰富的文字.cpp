class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans=0;
        for(auto word:words){
            int i=0,j=0;
            bool flag=true;
            if(s.length()<word.length()) continue;
            while(i<s.length()&&j<word.length()){
                char x=s[i],y=word[j];
                if(s[i]!=word[j]) {
                    flag=false;
                    break;
                }else{
                    int cnt1=0,cnt2=0;
                    while(s[i]==x){
                        i++;
                        cnt1++;
                    }
                    while(word[j]==y){
                        j++;
                        cnt2++;
                    }
                    if(cnt1==2&&cnt2<cnt1||cnt2>cnt1){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag&&i>=s.length()) ans++;
        }
        return ans;
    }
};