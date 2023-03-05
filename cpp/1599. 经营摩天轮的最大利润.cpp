class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int cnt=0,cnt1=0,benefit=0,maxBenefit=0,ans=-1;
        int rest=0;
        for(int i=0;i<customers.size();i++){
            cnt++;
            customers[i]+=rest;
            if(customers[i]>4){
                rest=customers[i]-4;
                benefit+=4*boardingCost;
            }else{
                benefit+=customers[i]*boardingCost;
                rest=0;
            }
            benefit-=runningCost;
            if(benefit>maxBenefit){
                maxBenefit=benefit;
                ans=cnt;
            }
        }
        while(rest>0){
            if(boardingCost*4-boardingCost<0){
                return ans;
            }
            cnt++;
            if(rest>4){
                rest=rest-4;
                benefit+=4*boardingCost;
            }else{
                benefit+=rest*boardingCost;
                rest=0;
            }
            benefit-=runningCost;
            if(benefit>maxBenefit){
                maxBenefit=benefit;
                ans=cnt;
            }
        }
        if(maxBenefit<0) return -1;
        return ans;
    }
};