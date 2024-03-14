class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        for(int i = n; i > 1; i--) {
            int index = max_element(arr.begin(), arr.begin() + i) - arr.begin();
            if(index == i - 1) continue;
            reverse(arr.begin(), arr.begin() + index + 1);
            reverse(arr.begin(), arr.begin() + i);
            res.push_back(index + 1);
            res.push_back(i);
        }
        return res;
    }
};