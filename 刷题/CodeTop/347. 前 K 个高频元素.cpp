class Solution {
public:
    int partition(vector<pair<int, int>>& values, int l, int r) {
        int i = l, j = r - 1, pivot = values[r].second;
        while(true) {
            while(i <= j && values[i].second < pivot) i++;
            while(i <= j && values[j].second > pivot) j--;
            if(i > j) break;
            swap(values[i++], values[j--]);
        }
        swap(values[i], values[r]);
        return i;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occur;
        for(auto num : nums) {
            occur[num]++;
        }
        vector<pair<int, int> > values;
        for(auto& kv : occur) {
            values.push_back(kv);
        }
        int n = values.size();
        int l = 0, r = n - 1;
        int index = rand() % (r - l + 1) + l; 
        swap(values[r], values[index]);
        int kk = n - k;
        while(l <= r) {
            int p = partition(values, l, r);
            if(p > kk) {
                r = p - 1;
            } else if(p < kk) {
                l = p + 1;
            } else {
                break;
            }
        }
        vector<int> res;
        for(int i = n - k; i < n; i++) {
            res.push_back(values[i].first);
        }
        return res;
    }
};