class Solution {
public:
    bool areNumbersAscending(string s) {
        int n=s.length(),i=0,maxNum=-1;
        while(i<n){
            if(s[i]==' '||s[i]<='z'&&s[i]>='a') {
                i++;
                continue;
            }
            int num=0;
            while(s[i]<='9'&&s[i]>='0'){
                num=num*10+s[i]-'0';
                i++;
            }
            if(num<=maxNum) return false;
            else{
                maxNum=num;
            }
        }
        return true;
    }
};