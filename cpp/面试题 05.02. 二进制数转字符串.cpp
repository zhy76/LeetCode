class Solution {
public:
    string printBin(double num) {
        string res="0.";
        while(num!=0&&res.size()<=32){
            num*=2.0;
            if(num>=1.0){
                res.push_back('1');
                num-=1;
            }else{
                res.push_back('0');
            }
        }
        return res.size()<=32?res:"ERROR";
    }
};