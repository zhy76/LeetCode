class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> hashTable;
        for(int i=0;i<knowledge.size();i++){
            hashTable[knowledge[i][0]]=knowledge[i][1];
        }
        string ans;
        for(int i=0;i<s.length();){
            if(s[i]=='('){
                string t="";
                i+=1;
                while(s[i]!=')'){
                    t+=s[i];
                    i++;
                }
                if(hashTable[t]=="") ans+="?";
                else ans+=hashTable[t];
                i++;
            }else {
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};