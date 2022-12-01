class Solution {
public:
    int distance(int x,int y,int xx,int yy){
        return abs(x-xx)+abs(y-yy);
    }
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans=-1;
        int minD=0x3fffffff;
        for(int i=0;i<points.size();i++){
            if(points[i][0]==x||points[i][1]==y){
                int d=distance(x,y,points[i][0],points[i][1]);
                if(d<minD){
                    minD=d;
                    ans=i;
                }
            }
        }
        return ans;
    }
};