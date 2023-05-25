class Solution {
public:
    vector<int> getDiff(string s){
        vector<int> diff;
        for(int i=1;i<s.length();i++){
            diff.push_back(s[i]-s[i-1]);
        }
        return diff;
    }
    string oddString(vector<string>& words) {
        int m=words.size();
        int n=words[0].size();
        vector<int> diff0=getDiff(words[0]);
        vector<int> diff1=getDiff(words[1]);
        if(diff0!=diff1){
            vector<int> diff2=getDiff(words[2]);
            if(diff0==diff2){
                return words[1];
            }else return words[0];
        }else{
            for(int i=2;i<m;i++){
                if(diff0!=getDiff(words[i])){
                    return words[i];
                }
            }
        }
        return "";
    }
};