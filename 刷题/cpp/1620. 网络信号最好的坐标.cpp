class Solution {
public:
    int distance(int x,int y,int i,int j){
        return (x-i)*(x-i)+(y-j)*(y-j);
    }
    bool check(int x,int y,int radius,int i,int j){
        if(distance(x,y,i,j)<=radius*radius) return true;
        return false;
    }
    int xinhao(int q,int x,int y,int i,int j){
        return floor(q/(1+sqrt((double)distance(x,y,i,j))));
    }
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int> ans(2);
        int maxxinhao=-1;
        for(int i=0;i<=50;i++){
            for(int j=0;j<=50;j++){
                int temp=0;
                int x,y,q;
                for(int k=0;k<towers.size();k++){
                    x=towers[k][0];
                    y=towers[k][1];
                    q=towers[k][2];
                    if(check(x,y,radius,i,j)){
                        temp+=xinhao(q,x,y,i,j);
                    }
                }
                if(temp>maxxinhao){
                    ans[0]=i,ans[1]=j;
                    maxxinhao=temp;
                }
            }
        }
        return ans;
    }
};
