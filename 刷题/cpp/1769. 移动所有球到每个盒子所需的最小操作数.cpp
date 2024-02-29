class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.length();
        vector<int> ans(n);
        int left=boxes[0]-'0',right=0,operation=0;
        for(int i=1;i<n;i++){
            if(boxes[i]=='1'){
                right++;
                operation+=i;
            }
        }   
        ans[0]=operation;
        for(int i=1;i<n;i++){
            operation+=left-right;
            if(boxes[i]=='1'){
                left++;
                right--;
            }
            ans[i]=operation;
        }
        return ans;
    }
};