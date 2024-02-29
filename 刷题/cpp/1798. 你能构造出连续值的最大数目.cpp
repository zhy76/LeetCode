class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int res=1;
        sort(coins.begin(),coins.end());
        for(auto &coin:coins){
            if(coin>res){
                break;
            }
            res+=coin;
            
        }
        return res;
    }
};