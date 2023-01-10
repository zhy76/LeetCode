class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n),target(n);
        for(int i=0;i<n;i++){
            perm[i]=i;
        }
        target=perm;
        int ans=0;
        while(true){
            vector<int> arr(n);
            ans++;
            for(int i=0;i<n;i++){
                if(i&1){
                    arr[i]=perm[n/2+(i-1)/2];
                }else{
                    arr[i]=perm[i/2];
                }
            }
            perm=move(arr);
            if(perm==target) break;
        }
        return ans;
    }
};