// 方法一：排序+前缀
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> ans={folder[0]};
        for(int i=1;i<folder.size();i++){
            string pre=ans.end()[-1];
            if(!(pre.size()<folder[i].size()&&pre==folder[i].substr(0,pre.size())&&folder[i][pre.size()]=='/')){
                ans.push_back(folder[i]);
            }    
        }
        return ans;
    }
};

// 方法二：字典树
struct Trie{
    Trie():ref(-1){}
    unordered_map<string,Trie*> children;
    int ref;
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        auto split=[](const string& s)->vector<string> {
            vector<string> ret;
            string cur;
            for (char ch:s){
                if(ch=='/'){
                    ret.push_back(move(cur));
                    cur.clear();
                }else{
                    cur.push_back(ch);
                }
            }
            ret.push_back(move(cur));
            return ret;
        };
        Trie* root=new Trie();
        for(int i=0;i<folder.size();i++){
            vector<string> path=split(folder[i]);
            Trie* cur=root;
            for(const string& name:path){
                if(!cur->children.count(name)){
                    cur->children[name]=new Trie();
                }
                cur=cur->children[name];
            }
            cur->ref=i;
        }
        vector<string> ans;

        function<void(Trie*)> dfs=[&](Trie* cur){
            if(cur->ref!=-1){
                ans.push_back(folder[cur->ref]);
                return;
            }
            for(auto&& [_,child]:cur->children){
                dfs(child);
            }
        };
        dfs(root);
        return ans;
    }
};