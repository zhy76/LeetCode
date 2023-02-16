class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,bool> mp;
        int res=0;
        for(auto num:nums){
            if(mp.count(num)){
                mp[num]=!mp[num];
            }else{
                mp[num]=true;
            }
            if(mp[num]==false){
                res++;
            }
        }
        return {res,(int)nums.size()-2*res};
    }   
};