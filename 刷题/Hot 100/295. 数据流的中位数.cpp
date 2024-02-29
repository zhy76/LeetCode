class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int> > queMin; //大顶堆,记录小于等于中位数的数
    priority_queue<int, vector<int> ,greater<int> > queMax; // 小顶堆，记录大于中位数的数
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(queMin.size() == queMax.size()) {
            queMin.push(num);
            queMax.push(queMin.top());
            queMin.pop();
        } else {
            queMax.push(num);
            queMin.push(queMax.top());
            queMax.pop();
        }
    }
    
    double findMedian() {
        if(queMin.size() != queMax.size()) {
            return queMax.top();
        }
        return (queMax.top() + queMin.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */