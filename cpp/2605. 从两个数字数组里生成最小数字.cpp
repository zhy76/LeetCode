class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<int> mp1(10);
        vector<int> mp2(10);
        for(auto num: nums1){
            mp1[num]=1;
        }
        for(auto num: nums2){
            mp2[num]=1;
        }
        int a=0,b=0;
        for(int i=1;i<=9;i++){
            if(mp1[i] && mp2[i]) return i;
            else if(!a && mp1[i]){
                a=i;
            }else if(!b && mp2[i]){
                b=i;
            }
        }
        return min(a*10+b,b*10+a);
    }
};