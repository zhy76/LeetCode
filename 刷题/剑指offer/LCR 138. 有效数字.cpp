class Solution {
public:
    bool isint(string s){
        if(s == "") return false;
        int st = 0, ed = s.size() - 1;
        if(s[0] == '-' || s[0] == '+') st++;
        for(int i = st; i <= ed; ++i){
            if(s[i] == ' ') return false;
            if(!isdigit(s[i])) return false;
        }
        return ed - st >= 0;
    }
    bool isfloat(string s){
        if(s == "") return false;
        int st = 0, ed = s.size() - 1;
        if(s[0] == '-' || s[0] == '+') st++;
        int pos = -1;
        for(int i = st; i <= ed; ++i){
            if(s[i] == ' ') return false;
            if(s[i] == '.') {
                if(pos != -1) return false;
                pos = i;
            } else if(!isdigit(s[i])) 
                return false;
        }
        return ed - st >= 1;
    }
    bool validNumber(string s) {
        int st = 0, ed = s.size() - 1;
        while(st < ed && s[st] == ' ') st++;
        while(ed > st && s[ed] == ' ') ed--;
        if(s[0] == '-' || s[0] == '+') st++;

        bool flag = false;
        for(int i = st; i <= ed; ++i){
            char ch = s[i];
            if(isalpha(ch)){
                if(ch != 'e' && ch != 'E') return false;
                string s1 = s.substr(st, i - st), s2 = s.substr(i + 1, ed - i);
                return (isint(s1) || isfloat(s1)) && isint(s2);
            }
        }
        string s3 = s.substr(st, ed - st + 1);
        return isint(s3) || isfloat(s3);
    }
};