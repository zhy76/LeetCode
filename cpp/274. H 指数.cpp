class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> cnt(n+1);
        for(int c:citations){
            cnt[min(c,n)]++;
        }
        int s=0;
        for(int i=n;i>=0;i--){
            s+=cnt[i];
            if(s>=i){
                return i;
            }
        }
        return 0;
    }
};