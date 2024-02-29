class Solution {
public:
    int countTime(string time) {
        int h=0,m=0;
        for(int i=time.size();i>=0;i--){
            if(time[i]=='?'){
                if(i==4){
                    m=10;
                }else if(i==3){
                    m=m==0?6:6*m;
                }else if(i==1){
                    if(time[0]<='1') h=10;
                    else h=4;
                }else if(i==0){
                    if(time[0]=='?'&&time[1]=='?'){
                        h=24;
                    }else if(time[1]>='4'){
                        h=2;
                    }else{
                        h=3;
                    }
                }
            }   
        }
        cout<<h<<" "<<m<<endl;
        return (h==0?1:h)*(m==0?1:m);
    }
};