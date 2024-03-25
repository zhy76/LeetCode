class Solution {
public:
    bool check(vector<int>& postorder, int l, int r) {
        if(l >= r) return true;
        int root = postorder[r];
        int i = l;
        while(i < r && postorder[i] < root) {
            i++;
        }
        int j = i;
        while(j < r && postorder[j] > root) {
            j++;
        }
        if(j != r) return false;
        return check(postorder, i, r - 1) && check(postorder, l, i - 1); 
    }

    bool verifyTreeOrder(vector<int>& postorder) {
        return check(postorder, 0, postorder.size() - 1);
    }
};