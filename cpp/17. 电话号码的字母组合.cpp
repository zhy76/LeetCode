class Solution {
public:
    void DFS(string digits,vector<string> &ans,int ind,vector<string> mp,string &t){
        if(ind==digits.size()){
            ans.emplace_back(t);
            return;
        }
        int key=digits[ind]-'1'+1;
        string letters=mp[key];
        for(auto letter:letters){
            t.push_back(letter);
            DFS(digits,ans,ind+1,mp,t);
            t.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()){
            return ans;
        }
        vector<string> mp(10);
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string t;
        DFS(digits,ans,0,mp,t);
        return ans;
    }
};