class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0;
        int d=0;
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        for(auto ins:instructions){
            if(ins=='G'){
                x+=dir[d%4][0];
                y+=dir[d%4][1];
            }else if(ins=='L'){
                d=(d+4-1)%4;
            }else if(ins=='R'){
                d=(d+1)%4;
            }
        }
       return d!=0 || (x==0&&y==0);
    }
};