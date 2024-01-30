class Checkout {
private:
    deque<int> qu;
    queue<int> q;
public:
    Checkout() {

    }
    
    int get_max() {
        return qu.empty()? -1: qu.front();
    }
    
    void add(int value) {
        while(!qu.empty() && qu.back() < value) {
            qu.pop_back();
        }
        q.push(value);
        qu.push_back(value);
    }
    
    int remove() {
        if(q.empty()) return -1;
        int x = q.front();
        if(x == qu.front()) {
            qu.pop_front();
        }
        q.pop();
        return x;
    }
};

/**
 * Your Checkout object will be instantiated and called as such:
 * Checkout* obj = new Checkout();
 * int param_1 = obj->get_max();
 * obj->add(value);
 * int param_3 = obj->remove();
 */