class Solution {
public:
    struct cmp {
        bool operator() (string a, string b) {
            if(a.size() == b.size()) {
                return a < b;
            } else {
                return a.size() > b.size();
            }
        }
    };
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), cmp());
        for(auto dic : dictionary) {
            int i = 0, j = 0;
            // cout<<dic<<endl;
            if(s.size() < dic.size()) continue;
            while(i < s.size() && j < dic.size()) {
                if(s[i] == dic[j]) {
                    i++, j++;
                } else {
                    i++;
                }
            }
            // cout<<i<<" "<<j<<endl;
            if(j == dic.size()) {
                return dic;
            }
        }
        return "";
    }
};