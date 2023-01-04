class Solution {
public:
    long long cal(int big,int length){
        if(big>length+1){
            return (long long)(big-1+big-length)*length/2;
        }else{
            return (long long)big*(big-1)/2+(length-big+1);
        }
    }
    bool valid(int big,int n,int index,int maxSum){
        int left=index,right=n-index-1;
        return cal(big,left)+cal(big,right)+big<=maxSum;
    }
    int maxValue(int n, int index, int maxSum) {
        int left=1,right=maxSum;
        while(left<right){
            int mid=(left+right+1)/2;
            cout<<left<<" "<<right<<" "<<mid<<" "<<valid(mid,n,index,maxSum)<<endl;
            if(valid(mid,n,index,maxSum)){
                left=mid;
            }else{
                right=mid-1;
            }
        }
        return left;
    }
};