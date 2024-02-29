class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans=0;
        int ind=0;
        if(ruleKey=="type") ind=0;
        if(ruleKey=="color") ind=1;
        if(ruleKey=="name") ind=2;
        for(int i=0;i<items.size();i++){
            if(items[i][ind]==ruleValue) ans++;
        }
        return ans;
    }
};
