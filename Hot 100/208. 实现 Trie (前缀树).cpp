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
        for(char ch: word) {
            int ind = ch - 'a';
            if(node->child[ind] == NULL) {
                node->child[ind] = new Trie();
            } 
            node = node->child[ind];
        }
        node->val = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char c: word) {
            node = node->child[c-'a'];
            if(node == NULL) return false;
        }
        return node->val;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c: prefix) {
            node = node->child[c-'a'];
            if(node == NULL) return false;
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