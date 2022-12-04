class Solution {
public:
    void dfs(vector<int>& toppingCosts,int ind,int target,int &res,int p){
        if(abs(res-target)<p-target){
            return;
        }else if(abs(res-target)>=abs(p-target)){
            if(abs(res-target)>abs(p-target)){
                res=p;
            }else{
                res=min(res,p);
            }
        }
        
        if(ind==toppingCosts.size()){
            return;
        }
        if(p+res)
        dfs(toppingCosts,ind+1,target,res,p+toppingCosts[ind]);
        dfs(toppingCosts,ind+1,target,res,p+2*toppingCosts[ind]);
        dfs(toppingCosts,ind+1,target,res,p);
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
       int res=*min_element(baseCosts.begin(),baseCosts.end());
       for(auto &base:baseCosts){
            dfs(toppingCosts,0,target,res,base);
       }
       return res;

    }
};