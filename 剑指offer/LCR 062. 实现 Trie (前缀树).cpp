class Trie {
private:
    struct Node {
        bool val;
        vector<Node*> child;
        Node() {
            val = false;
            child = vector<Node*>(26, NULL);
        }
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(char c : word) {
            int ind = c - 'a';
            if(node->child[ind] == NULL) {
                node->child[ind] = new Node();
            }
            node = node->child[ind];
        }
        node->val = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(char c : word) {
            int ind = c - 'a';
            if(node->child[ind] == NULL) return false;
            node = node->child[ind];
        }
        return node->val;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *node = root;
        for(char c : prefix) {
            int ind = c - 'a';
            if(node->child[ind] == NULL) return false;
            node = node->child[ind];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */