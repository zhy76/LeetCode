class Solution {
public:
    bool check(string x){
        int n=x.length();
        for(int i=0;i<=n/2;i++){
            if(x[i]!=x[n-i-1]) return false;
        }
        return true;
    }
    bool checkAB(const string &a,const string &b){
        int n=a.size();
        int left=0, right=n-1;
        while(left<right && a[left]==b[right]){
            left++;
            right--;
        }
        if(left>=right){
            return true;
        }
        return check(a.substr(left,right-left+1)) || check(b.substr(left,right-left+1));
    }
    bool checkPalindromeFormation(string a, string b) {
        return checkAB(a,b) || checkAB(b,a);
    }
};