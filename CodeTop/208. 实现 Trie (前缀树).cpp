class Trie {
private:
    bool val;
    vector<Trie*> child;
public:
    Trie() {
        val = false;
        child = vector<Trie*>(26, NULL);
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char c : word) {
            int ind = c - 'a';
            if(node->child[ind] == NULL) {
                node->child[ind] = new Trie();
            }
            node = node->child[ind];
        }
        node->val = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c : word) {
            int ind = c - 'a';
            if(node->child[ind] == NULL) return false;
            node = node->child[ind];
        }
        return node->val;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
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