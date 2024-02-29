class Solution {
public:
    int minimumDeletions(string s) {
        int leftb=0,righta=0;
        for(auto ch:s){
            if(ch=='a'){
                righta++;
            }
        }
        int res=righta;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                righta--;
            }else{
                leftb++;
            }
            res=min(res,leftb+righta);
        }
        return res;
    }
};