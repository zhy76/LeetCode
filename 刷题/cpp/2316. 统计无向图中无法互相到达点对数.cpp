class Solution {
private:
    vector<int> father;
    vector<int> sizes;
public:
    int findFather(int x){
        if(x==father[x]){
            return x;
        }
        int F=findFather(father[x]);
        father[x]=F;
        return F;
    }
    void Union(int x, int y){
        int fx=findFather(x);
        int fy=findFather(y);
        if(fx != fy){
            if(sizes[fx] > sizes[fy]){
                father[fy]=fx;
                sizes[fx]+=sizes[fy];
            }else{
                father[fx]=fy;
                sizes[fy]+=sizes[fx];
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++){
            father.push_back(i);
            sizes.push_back(1);
        }
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0];
            int b=edges[i][1];
            Union(a, b);
        }
        long long res=0;
        for(int i=0;i<n;i++){
            res+=n-sizes[findFather(i)];
        }
        return res/2;
    }
};