class MyStack {
public:
    queue<int> qu;
    MyStack() {

    }
    
    void push(int x) {
        int n = qu.size();
        qu.push(x);
        for(int i=0; i<n; i++) {
            qu.push(qu.front());
            qu.pop();
        }
    }
    
    int pop() {
        int x = qu.front();
        qu.pop();
        return x;
    }
    
    int top() {
        return qu.front();
    }
    
    bool empty() {
        return qu.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */