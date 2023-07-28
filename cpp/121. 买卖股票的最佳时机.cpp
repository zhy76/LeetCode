class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice=prices[0];
        int ans=0;
        for(int i=0;i<prices.size();i++){
            if (prices[i]<minprice){
                minprice=prices[i];
            }else if(prices[i]-minprice>ans){
                ans=prices[i]-minprice;
            }
        }
        return ans;
    }
};