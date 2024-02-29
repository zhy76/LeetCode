class Solution {
public:
    bool dfs(string s,int pos, int sum, int target){
        if (pos == s.size()){
            return sum == target;
        }
        int t=0;
        for(int i=pos; i<s.size();i++){
            t=t*10+s[i]-'0';
            if(t+sum > target) {
                break;
            }
            if(dfs(s, i+1, t+sum, target)) {
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int res=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i*i);
            if(dfs(s, 0, 0, i)){
                res+=i*i;
            }
        }
        return res;
    }
};