class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int ind=-1;
        int res=0;
        unordered_map<int,int> count;
        count[0]=1;
        for(int i=0;i<n;i++){
            if(nums[i]>k){
                nums[i]=1;
            }else if(nums[i]<k){
                nums[i]=-1;
            }else if(nums[i]==k){
                nums[i]=0;
                ind=i;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if (i<ind){
                count[sum]++;
            }else{
                res+=count[sum]+count[sum-1];
            }
        }
        return res;
    }
};