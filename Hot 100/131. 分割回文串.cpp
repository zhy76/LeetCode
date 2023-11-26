class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> path;
        int n=s.length();
        function<void(int)> dfs = [&](int i) {
            if(i==n) {
                ans.push_back(path);
                return;
            }
            for(int j=i; j<n; j++) {
                if(isPalindrome(s, i ,j)) {
                    path.push_back(s.substr(i, j-i+1));
                    dfs(j+1);
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};