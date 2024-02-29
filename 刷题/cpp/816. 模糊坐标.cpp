class Solution {
public:
    vector<string> getPos(string s){
        vector<string> pos;
        if(s[0]!='0'||s=="0") pos.emplace_back(s);
        for(int i=1;i<s.size();i++){
            if((i!=1&&s[0]=='0')||s.back()=='0') continue;
            pos.emplace_back(s.substr(0,i)+'.'+s.substr(i));
        }
        return pos;
    }
    vector<string> ambiguousCoordinates(string s) {
        int n=s.size()-2;
        vector<string> res;
        s=s.substr(1,n);
        for(int l=1;l<n;l++){
            vector<string> lt=getPos(s.substr(0,l));
            if(lt.empty()) continue;
            vector<string> rt=getPos(s.substr(l));
            if(rt.empty()) continue;
            for(auto& i:lt){
                for(auto& j:rt){
                    res.emplace_back('('+i+", "+j+')');
                }
            }
        }
        return res;
    }
};