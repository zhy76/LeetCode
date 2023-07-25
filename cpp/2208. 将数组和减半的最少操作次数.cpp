class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> qu;
        int n=nums.size();
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            qu.push(nums[i]);
        }
        double cursum=sum;
        int cnt=0;
        while(cursum>sum/2){
            double now=qu.top();
            qu.pop();
            now=now/2;
            cursum-=now;
            qu.push(now);
            cnt++;
        }
        return cnt;
    }
};