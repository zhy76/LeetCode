//方法一：深度优先搜索 
class Solution {
private:
    set<string> st;
    vector<string> ans;
public:
    void dfs(int ind,int n,string t){
        if(ind==n){
            return;
        }
        for(int i=ind;i<n;i++){
            if(!st.count(t)){
                st.insert(t);
                ans.emplace_back(t);
                dfs(ind+1,n,t);
            }
            if(isalpha(t[i])){
                string temp=t;
                if(islower(t[i])) temp[i]=toupper(t[i]);
                else if(isupper(t[i])) temp[i]=tolower(t[i]);
                if(!st.count(temp)){
                    st.insert(temp);
                    ans.emplace_back(temp);
                    dfs(ind+1,n,temp);
                }
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        int n=s.length();
        dfs(0,n,s);
        return ans;
    }
};
//广度优先搜索
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        queue<string> qu;
        vector<string> ans;
        qu.emplace("");
        while(!qu.empty()){
            string &now=qu.front();
            if(now.size()==s.size()){
                ans.emplace_back(now);
                qu.pop();
            }else{
                int pos=now.size();
                if(isalpha(s[pos])){
                    string next=now;
                    next+=(s[pos]^32);
                    qu.emplace(next);
                }
                now+=s[pos];
            }
        }
        return ans;
    }
}; 
//位图
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n=s.size();
        int m=0;
        for(int i=0;i<n;i++){
            if(isalpha(s[i])) m++;
        }
        vector<string> ans;
        for(int mask=0;mask<(1<<m);mask++){
            string str;
            for(int i=0,k=0;i<n;i++){
                if(isalpha(s[i])&&(mask&(1<<k++))){
                    str.push_back(toupper(s[i]));
                }else{
                    str.push_back(tolower(s[i]));
                }
            }
            ans.emplace_back(str);
        }
        return ans;
    }
};
