class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int maxNum=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=gain[i];
            if(sum>maxNum){
                maxNum=sum;
            }
        }
        return maxNum;
    }
};