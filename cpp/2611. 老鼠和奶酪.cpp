class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size();
        vector<int> result(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=reward2[i];
            result[i]=reward1[i]-reward2[i];
        }
        sort(result.begin(),result.end());
        for(int i=1;i<=k;i++){
            sum+=result[n-i];
        }
        return sum;
    }
};