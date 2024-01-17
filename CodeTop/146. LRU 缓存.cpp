class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int k,int v) {
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };
    unordered_map<int, Node*> cache;
    int cap;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }

    void addLast(Node* node) {
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    Node* removeFront() {
        if(head->next == tail) return NULL;
        Node* node = head->next;
        remove(node);
        return node;
    }

    void removeToLast(Node* node) {
        remove(node);
        addLast(node);
    }
    
    int get(int key) {
        if(cache.count(key)) {
            removeToLast(cache[key]);
            return cache[key]->value;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            Node* node = cache[key];
            node->value = value;
            removeToLast(node);
        } else {
            Node* node = new Node(key, value);
            addLast(node);
            cache[key] = node;
            if(cache.size() > cap) {
                Node* node = removeFront();
                cache.erase(node->key);
                delete node;
            }
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */