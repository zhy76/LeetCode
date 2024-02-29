class Solution {
public:
    deque<string> track;
    vector<string> res;
    void backtrack(string s, int ind) {
        if(ind == s.length()) {
            if(track.size() == 4) {
                string tmp = "";
                for(int i = 0; i < track.size(); i++) {
                    tmp += track[i];
                    if(i != track.size() - 1) {
                        tmp += ".";
                    }
                }
                res.push_back(tmp);
                return;
            } else return;
        }
        for(int i = ind; i < s.length(); i++) {
            if(!valid(s, ind, i)) {
                continue;
            }
            track.push_back(s.substr(ind, i - ind + 1));
            backtrack(s, i + 1);
            track.pop_back();
        }
    }
    bool valid(string s, int ind, int i) {
        string tmp = s.substr(ind, i - ind + 1);
        if(tmp.size() > 1 && tmp[0] == '0') return false;
        if(tmp.size() >= 4) return false;
        int sum = 0;
        int p = 1;
        for(int j = tmp.size() - 1; j >= 0; j--) {
            if(tmp[j] < '0' || tmp[j] > '9') return false;
            sum += (tmp[j] - '0') * p;
            p *= 10;
        }
        if(sum > 255) return false;
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0);
        return res;
    }   
};