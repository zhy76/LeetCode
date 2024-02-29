class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for(auto operation: operations){
            int x=operation[0],y=operation[1];
            int z=gem[x]/2;
            gem[y]+=z;
            gem[x]-=z;
        }
        sort(gem.begin(),gem.end());
        return gem[gem.size()-1]-gem[0];
    }
};