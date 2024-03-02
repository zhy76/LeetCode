class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> st;
        int remain = num.size() - k;
        for(int i = 0; i < num.size(); i++) {
            while(k && !st.empty() && st.back() > num[i]) {
                k--;
                st.pop_back();
            }
            st.push_back(num[i]);
        }
        string res = string(st.begin(), st.begin() + remain);
        while(res.size() && res[0] == '0') {
            res.erase(res.begin());
        }
        return res.size() == 0? "0":res;
    }
};