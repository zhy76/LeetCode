class CQueue {
private:
    stack<int> st1;
    stack<int> st2;
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if(!st2.empty()) {
            int res = st2.top();
            st2.pop();
            return res;
        } else {
            if(st1.empty()) return -1;
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            int res = st2.top();
            st2.pop();
            return res;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */