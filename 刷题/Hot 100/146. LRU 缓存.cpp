class Node{
public:
    int key, value;
    Node* pre;
    Node* next;
    Node(int _key=0, int _value=0): key(_key), value(_value){}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    int capacity;
    Node* dummy;
public:
    LRUCache(int _capacity):capacity(_capacity), dummy(new Node()) {
        dummy->pre=dummy;
        dummy->next=dummy;
    }

    void remove(Node* node) {
        node->pre->next=node->next;
        node->next->pre=node->pre;
    }

    void addToFront(Node* node) {
        node->pre=dummy;
        node->next=dummy->next;
        dummy->next->pre=node;
        dummy->next=node;
    }

    Node* get_node(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return NULL;
        }
        auto node = it->second;
        remove(node);
        addToFront(node);
        return node;
    }

    int get(int key) {
        Node *node = get_node(key);
        if(node != NULL) {
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* node = get_node(key);
        if(node!=NULL) {
            node->value = value;
            return;
        }
        cache[key] = node = new Node(key, value);
        addToFront(node);
        if(cache.size() > capacity) {
            Node* tail_node = dummy->pre;
            cache.erase(tail_node->key);
            remove(tail_node);
            delete(tail_node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */