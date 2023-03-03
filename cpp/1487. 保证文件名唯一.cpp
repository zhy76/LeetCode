class Solution {
public:
    string addSuffix(string name,int k){
        return name+"("+to_string(k)+")";
    }
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> mp;
        vector<string> res;
        for(auto &name:names){
            if(!mp.count(name)){
                res.push_back(name);
                mp[name]=1;
            }else{
                int k=mp[name];
                string tmp=name;
                while(mp.count(tmp)){
                    tmp=addSuffix(name,k);
                    k++;
                }
                mp[name]=k;
                res.push_back(tmp);
                mp[tmp]=1;
            }
        }
        return res;
    }
};