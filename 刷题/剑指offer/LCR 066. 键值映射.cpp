class MapSum {
private:
    struct Node {
        int val;
        vector<Node*> child;
        Node() {
            val = 0;
            child = vector<Node*>(26, NULL);
        } 
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        Node* node = root;
        for(char c : key) {
            int ind = c - 'a';
            if(node->child[ind] == NULL) {
                node->child[ind] = new Node();
            }
            node = node->child[ind];
        }
        node->val = val;
    }
    
    int sum(string prefix) {
        Node* node = root;
        for(char c : prefix) {
            int ind = c - 'a';
            if(node->child[ind] == NULL) return 0;
            node = node->child[ind];
        }

        int sum = 0;
        traverse(node, sum);
        return sum;
    }

    void traverse(Node* node, int& sum) {
        if(node == NULL) {
            return;
        }
        sum += node->val;
        for(int i = 0; i < 26; i++) {
            if(node->child[i] == NULL) continue;
            traverse(node->child[i], sum);
        }
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */