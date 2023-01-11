class Solution {
public:
    bool digitCount(string num) {
        int n=num.size();
        int a[10]={0};
        for(int i=0;i<n;i++){
            a[num[i]-'0']++;
        }
        for(int i=0;i<n;i++){
            if(a[i]==(num[i]-'0')) continue;
            else {
                return false;
            }
        }
        return true;
    }
};