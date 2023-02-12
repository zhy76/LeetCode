class Solution {
public:
    string alphabetBoardPath(string target) {
        string res;
        int x=0,y=0;
        for(auto ch:target){
            int tx=(ch-'a')/5;
            int ty=(ch-'a')%5;
            if(tx<x){
                res.append(x-tx,'U');
            }
            if(ty<y){
                res.append(y-ty,'L');
            }
            if(ty>y){
                res.append(ty-y,'R');
            }
            if(tx>x){
                res.append(tx-x,'D');
            }
            res.push_back('!');
            x=tx,y=ty;
        }
        return res;
    }
};