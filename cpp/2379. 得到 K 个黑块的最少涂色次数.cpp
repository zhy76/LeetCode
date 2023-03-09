class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0,j=k-1;
        int ans=blocks.length();
        while(j<=blocks.length()){
            int cnt=0;
            for(int h=i;h<=j;h++){
                if(blocks[h]=='B'){
                    cnt++;
                }
            }
            ans=min(ans,k-cnt);
            i++,j++;
        }
        return ans;
    }
};