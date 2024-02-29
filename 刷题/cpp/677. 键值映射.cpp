struct Trie{
    int val;
    vector<Trie*> child;
    Trie() {
        val = 0;
        child = vector<Trie*>(26, NULL);
    }
};

class MapSum {
private:
    Trie* root;

public:
    MapSum() {
        this->root = new Trie();
    }
    
    void insert(string key, int val) {
        Trie* node = root;
        for(char c: key) {
            if(node->child[c - 'a'] == NULL) {
                node->child[c - 'a'] = new Trie();
            }
            node = node->child[c - 'a']; 
        }
        node->val = val;
    }

    int traverse(Trie* node) {
        int sum = 0;
        if(node == NULL) return 0;
        sum += node->val;
        for(int i=0; i<26; i++) {
            sum += traverse(node->child[i]);
        }
        return sum;
    }

    int sum(string prefix) {
        Trie* node = root;
        for(char c: prefix) {
            node = node->child[c- 'a'];
            if(node == NULL) {
                return 0;
            }
        }
        return traverse(node);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */