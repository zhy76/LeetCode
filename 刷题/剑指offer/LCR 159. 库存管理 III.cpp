class Solution {
public:
    int patition(vector<int>& nums, int l, int r) {
        int i = l, j = r - 1, pivot = nums[r];
        while(true) {
            while(i <= j && nums[i] < pivot) i++;
            while(i <= j && nums[j] > pivot) j--;
            if(i > j) break;
            swap(nums[i++], nums[j--]);
        }
        swap(nums[i], nums[r]);
        return i;
    }
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        int l = 0, r = stock.size() - 1;
        while(l <= r) {
            int p = patition(stock, l, r);
            if(p == cnt) {
                break;
            } else if(p < cnt) {
                l = p + 1;
            } else {
                r = p - 1;
            }
        }
        vector<int> res;
        for(int i = 0; i < cnt; i++) {
            res.push_back(stock[i]);
        }
        return res;
    }
};