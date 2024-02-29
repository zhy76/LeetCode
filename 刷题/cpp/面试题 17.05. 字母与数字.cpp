class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int sum=0,n=array.size();
        unordered_map<int,int> mp;
        mp[0]=-1;
        int k=0;
        int maxL=0;
        for(int i=0;i<array.size();i++){
            sum+=isalpha(array[i][0])?1:-1;
            if(mp.count(sum)){
                int j=mp[sum];
                if(i-j>maxL){
                    maxL=i-j;
                    k=j+1;
                }
            }else{
               mp[sum]=i;
            }
        }
        return vector<string>(array.begin()+k,array.begin()+k+maxL);
    }
};