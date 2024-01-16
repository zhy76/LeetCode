// 方法一：堆
class Solution {
public:
    struct node {
        int val;
        int count;
        friend bool operator < (const node& x, const node& y) {
            return x.count > y.count;
        }
        node(int val, int count) {
            this->val = val;
            this->count = count;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<node> qu;
        unordered_map<int, int> occur;
        for(auto num:nums) {
            occur[num]++;
        }
        for(auto& [num, count]:occur) {
            if(qu.size() == k) {
                if(qu.top().count < count) {
                    qu.pop();
                    qu.push({num, count});
                }
            } else {
                qu.push({num, count});
            }
        }
        vector<int> ans;
        while(!qu.empty()) {
            ans.push_back(qu.top().val);
            qu.pop();
        }
        return ans;
    }
};

// 方法二：快速排序
class Solution {
public:
    int partition(vector<pair<int, int>>& values, int l, int r) {
        int i = l, j = r - 1, pivot = values[r].second;
        while (true) {
            while (i <= j && values[i].second < pivot) i++;
            while (i <= j && values[j].second > pivot) j--;
            if (i > j) break;
            swap(values[i++], values[j--]);
        }
        swap(values[i], values[r]);
        return i;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occur;
        for (auto num : nums) {
            occur[num]++;
        }

        vector<pair<int, int>> values;
        for (auto& kv : occur) {
            values.push_back(kv);
        }

        vector<int> ans;
        int l = 0, r = values.size() - 1;
        int index = rand() % (r - l + 1) + l;
        int kk = values.size() - k;
        swap(values[index], values[r]);

        while (l <= r) {
            int p = partition(values, l, r);
            if (kk < p) {
                r = p - 1;
            } else if (kk > p) {
                l = p + 1;
            } else {
                break; // 找到正确的分区后退出循环
            }
        }

        // 确保只添加前 k 个元素
        for (int i = values.size() - k; i < values.size(); i++) {
            ans.push_back(values[i].first);
        }

        return ans;
    }
};