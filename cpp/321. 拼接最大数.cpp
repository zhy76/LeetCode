class Solution {
public:
    // 从nums数组中选择k个数，使得新数组字典序最大并且不改变数字的顺序
    vector<int> getMax(vector<int>& nums, int k) {
        stack<int> stk;
        // 选择k个数，就是要丢掉n-k个数
        int drop = nums.size() - k;
        for(auto num: nums) {
            // 单调递减栈
            while(!stk.empty() && drop && stk.top() < num) {
                stk.pop();
                // 每丢一个数，k--
                drop--;
            }
            stk.push(num);
        }
        // 如果k>0，说明还余有k个数没有丢掉,这时把末尾的k个数丢掉
        while(drop && !stk.empty()) {
            stk.pop();
            drop--;
        }
        vector<int> res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        int i = 0, j = 0;
        vector<int> res;
        while(i<nums1.size() && j<nums2.size()) {
            if(compare(nums1, i, nums2, j) > 0) {
                res.push_back(nums1[i++]);
            } else {
                res.push_back(nums2[j++]);
            }
        }
        while(i<nums1.size()) {
            res.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()) {
            res.push_back(nums2[j]);
            j++;
        }
        return res;
    }
    int compare(vector<int>& x, int i, vector<int>& y, int j) {
        while(i<x.size() && j<y.size()) {
            int diff = x[i++] - y[j++];
            if(diff != 0) return diff;
        }
        return (x.size() - i) - (y.size() - j);
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k, 0);
        for(int i=0; i<=k; i++) {
            if(i<=nums1.size() && k-i <= nums2.size()) {
                vector<int> merged = merge(getMax(nums1, i), getMax(nums2, k-i));
                if(compare(merged, 0, ans, 0) > 0) {
                    ans = merged;
                }
            }
           
        }
        return ans;
    }
};