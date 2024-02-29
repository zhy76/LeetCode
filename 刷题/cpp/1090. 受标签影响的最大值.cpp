class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n=values.size();
        vector<int> id(n);
        iota(id.begin(),id.end(),0);
        sort(id.begin(),id.end(),[&](int x,int y){
            return values[x]>values[y];
        });
        unordered_map<int,int> used;
        int sum=0;
        for(int i=0;i<n;i++){
            int value=values[id[i]];
            if(used[labels[id[i]]]==useLimit){
                continue;
            }else if(numWanted==0){
                break;
            }else{
                sum+=value;
                numWanted--;
                used[labels[id[i]]]++;
            }
        }
        return sum;

    }
};