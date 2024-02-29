class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool flag=true;
        for(int i=1;i<suits.size();i++){
            if(suits[i-1]!=suits[i]){
                flag=false;
                break;
            }
        }
        if(flag){
            return "Flush";
        }
        unordered_map<int,int> a;
        for(auto rank:ranks){
            a[rank]++;
        }
        for(int i=1;i<=13;i++){
            if(a[i]>=3){
                return "Three of a Kind";
            }
        }
        for(int i=1;i<=13;i++){
             if(a[i]>=2){
                return "Pair";
            }
        }
        return "High Card";
    }
};