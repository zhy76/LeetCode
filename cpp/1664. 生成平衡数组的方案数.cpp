class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<int> preOdd(n+1),preEven(n+1); 
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(i==1){
                preOdd[i]=nums[i];
            }else if(i&1){
                preOdd[i]=nums[i]+preOdd[i-2];
            }
            else if(i>0){
                preOdd[i]=preOdd[i-1];
            }
            if(i==0){
                preEven[i]=nums[i];
            }else if((i&1)==0){
                preEven[i]=preEven[i-2]+nums[i];
            }else if(i>0){
                preEven[i]=preEven[i-1];
            }
            // cout<<i<<" "<<preOdd[i]<<" "<<preEven[i]<<endl;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int oddLeft=(i==0?0:preOdd[i-1]),evenRight=preEven[n-1]-preEven[i];
            // cout<<"left:"<<oddLeft<<" right:"<<evenRight<<" sum:"<<sum<<endl;
            if((oddLeft+evenRight)*2+nums[i]==sum){
                ans++;
            }
        }
        return ans;
    }
};