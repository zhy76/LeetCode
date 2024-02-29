class Solution {
public:
    int alternateDigitSum(int n) {
        string s=to_string(n);
        int sum=0;
        int p=1;
        for(int i=0;i<s.length();i++){
            sum+=(s[i]-'0')*p;
            p=-p;
        }
        return sum;
    }
};