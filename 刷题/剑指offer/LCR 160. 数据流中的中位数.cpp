class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> qu1;
    priority_queue<int, vector<int>, greater<int>> qu2;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(qu1.size() >= qu2.size()) {
            qu1.push(num);
            qu2.push(qu1.top());
            qu1.pop();
        } else if(qu1.size() < qu2.size()) {
            qu2.push(num);
            qu1.push(qu2.top());
            qu2.pop();
        }
    }
    
    double findMedian() {
        if(qu1.size() == qu2.size()) {
            return (qu1.top() + qu2.top()) / 2.0;
        } else {
            return qu2.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */