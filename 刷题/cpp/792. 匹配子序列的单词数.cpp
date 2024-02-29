//法一：分桶
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<queue<string>> d(26);
        for(auto& w:words){
            d[w[0]-'a'].emplace(w);
        }
        int ans=0;
        for(auto c:s){
            auto&& q=d[c-'a'];
            int size=q.size();
            while(size--){
                string t=q.front();
                q.pop();
                if(t.length()==1) ans++;
                else d[t[1]-'a'].emplace(t.substr(1));
            }
        }
        return ans;
    }
};
//法二：二分查找
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for(int i=0;i<s.length();i++){
            pos[s[i]-'a'].emplace_back(i);
        }
        int ans=words.size();
        for(auto str:words){
            if(str.length()>s.length()){
                ans--;
                continue;
            }
            int p=-1;
            for(char c:str){
                auto &ps=pos[c-'a'];
                auto it=upper_bound(ps.begin(),ps.end(),p);
                if(it==ps.end()){
                    ans--;
                    break;
                }
                p=*it;
            }
        }
        return ans;
    }
};