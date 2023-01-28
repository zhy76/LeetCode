class Solution {
private:
    int hashLow[26],hashHigh[26];
public:
    string greatestLetter(string s) {
        for(auto ch:s){
            if(ch>='a'&&ch<='z'){
                hashLow[ch-'a']=1;
            }else if(ch>='A'&&ch<='Z'){
                hashHigh[ch-'A']=1;
            }
        }
        for(int i=25;i>=0;i--){
            if(hashHigh[i]&&hashLow[i]){
                return string(1,'A'+i);
            }
        }
        return "";
    }
};