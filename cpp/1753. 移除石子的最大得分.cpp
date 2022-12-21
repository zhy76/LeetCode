class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> qu;
        qu.push(a);
        qu.push(b);
        qu.push(c);
        int ans=0;
        while(true){
            int x=qu.top();
            qu.pop();
            int y=qu.top();
            qu.pop();
            if(y==0) break;
            x--,y--,ans++;
            qu.push(x);
            qu.push(y);
        }
        return ans;
    }
};