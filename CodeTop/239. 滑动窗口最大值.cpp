class Solution {
public:
    deque<int> qu;
    void push(int x) {
        while(!qu.empty() && x > qu.back()) {
            qu.pop_back();
        }
        qu.push_back(x);
    }
    void pop(int x) {
        if(qu.front() == x) {
            qu.pop_front();
        }
    }
    int getMax() {
        return qu.front();
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            if(i<k - 1) {
                push(nums[i]);
            } else {
                push(nums[i]);
                res.push_back(getMax());
                pop(nums[i-k+1]);
            }
        }
        return res;
    }
};