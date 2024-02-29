class Qu{
private:
    deque<int> qu;
public:
    void push(int x) {
        while(!qu.empty() && qu.back() < x) {
            qu.pop_back();
        }
        qu.push_back(x);
    }
    void pop(int x) {
        if(x == qu.front()) {
            qu.pop_front();
        }
    }
    int getMax() {
        return qu.front();
    }
};
class Solution {
public:
    vector<int> maxAltitude(vector<int>& heights, int limit) {
        Qu qu;
        vector<int> res;
        for(int i=0; i<heights.size(); i++) {
            if(i < limit - 1) {
                qu.push(heights[i]);
            } else {
                qu.push(heights[i]);
                res.push_back(qu.getMax());
                qu.pop(heights[i-limit+1]);
            }
        }
        return res;
    }
};