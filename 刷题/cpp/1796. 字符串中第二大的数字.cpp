class Solution {
public:
    int secondHighest(string s) {
        int maxNum=-1,secondNum=-1;
        for(auto ch:s){
            if(ch<='9'&&ch>='0'){
                int d=ch-'0';
                if(d>maxNum){
                    secondNum=maxNum;
                    maxNum=d;
                }else if(d<maxNum&&d>secondNum){
                    secondNum=d;
                }
            }
        }
        return secondNum;
    }
};