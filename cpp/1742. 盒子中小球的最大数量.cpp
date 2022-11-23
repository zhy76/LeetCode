class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        vector<int> box(60);
        int ans=0;
        for(int i=lowLimit;i<=highLimit;i++){
            int res=0;
            int t=i;
            while(t){
                res+=t%10;
                t/=10;
            }
            box[res]++;
            ans=max(ans,box[res]);
        }
        return ans;
    }
};