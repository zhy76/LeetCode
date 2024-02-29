class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unordered_map<int,bool> hashMap;
        if(k%2==0||k%5==0){
            return -1;
        }
        int len=1;
        int resid=1%k;
        while(resid!=0){
            resid=(resid*10+1)%k;
            len++;
            if(hashMap[resid]){
                return -1;
            }
           
            hashMap[resid]=true;
        }
        return len;
    }
};