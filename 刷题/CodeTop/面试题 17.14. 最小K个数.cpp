class Solution {
public:
    int partition(vector<int>& arr, int l, int r) {
        int i = l, j = r - 1, pivot = arr[r];
        while(true) {
            while(i <= j && arr[i] < pivot) i++;
            while(i <= j && arr[j] > pivot) j--;
            if(i > j) break;
            swap(arr[i++], arr[j--]);
        }
        swap(arr[i], arr[r]);
        return i;
    }
    vector<int> smallestK(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, r = n - 1;
        int p = 0;
        while(l <= r) {
            p = partition(arr, l, r);
            if(p == k) {
                break;
            } else if(p > k) {
                r = p - 1;
            } else if(p < k) {
                l = p + 1;
            }
        }
        vector<int> res;
        for(int i = 0; i < p; i++) {
            res.push_back(arr[i]);
        }
        return res;
    }
};