class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> mp;
        char cur='a';
        for(auto ch:key){
            if(ch!=' '&&!mp.count(ch)){
                mp[ch]=cur++;
            }
               
        }
        for(auto &ch:message){
            if(ch!=' '){
                ch=mp[ch];
            }    
        }
        return message;
    }
};