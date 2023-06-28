class Solution {
public:
    int pivotInteger(int n) {
        int t=n*(n+1)/2;
        int x=sqrt(t);
        if (x*x==t){
            return x;
        }
        return -1;
    }
};