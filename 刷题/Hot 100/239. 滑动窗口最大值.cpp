class MonotonicQueue {
private:
    deque<int> qu;
public:
    void push(int x) {
        while(!qu.empty() && qu.back() < x) {
            qu.pop_back();
        }
        qu.push_back(x);
    }

    int getMax() {
        return qu.front();
    }

    void pop(int x) {
        if(x == qu.front()) {
            qu.pop_front();
        }
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue window;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++) {
            if(i < k-1) {
                window.push(nums[i]);
            } else {
                window.push(nums[i]);
                ans.push_back(window.getMax());
                window.pop(nums[i-k+1]);
            }
        }
        return ans;
    }
};