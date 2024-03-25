class Solution {
public:
    bool isint(string s) {
        if(s == "") return false;
        int st = 0, ed = s.size() - 1;
        if(s[0] == '-' || s[0] == '+') st++;
        for(int i = st; i <= ed; i++) {
            if(!isdigit(s[i])) return false;
        } 
        return ed - st >= 0;
    }

    bool isfloat(string s) {
        if(s == "") return false;
        int st = 0, ed = s.size() - 1;
        if(s[0] == '+' || s[0] == '-') st++;
        int pos = -1;
        for(int i = st; i <= ed; i++) {
            if(s[i] == '.') {
                if(pos != -1) return false;    
                pos = i;
                
            } else if(!isdigit(s[i])) return false;
        }
        return ed - st >= 1;
    }

    bool validNumber(string s) {
        int l = 0, r = s.size() - 1;
        while(l < s.size() && s[l] == ' ') l++;
        while(r >= 0 && s[r] == ' ') r--;
        s = s.substr(l, r - l + 1);
        for(int i = 0; i < s.size(); i++) {
            if(isalpha(s[i])) {
                if(s[i] != 'e' && s[i] != 'E') return false;
                string s1 = s.substr(0, i);
                string s2 = s.substr(i + 1, s.size() - 1 - i);
                return (isint(s1) || isfloat(s1)) && isint(s2);
            }
        }
        return isint(s) || isfloat(s);
    }
};