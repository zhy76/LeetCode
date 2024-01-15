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