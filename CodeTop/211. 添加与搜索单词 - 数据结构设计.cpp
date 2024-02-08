class WordDictionary {
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
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(char c : word) {
            int ind = c - 'a';
            if(node->child[ind] == NULL) node->child[ind] = new Node();
            node = node->child[ind];
        }
        node->val = true;
    }
    bool traverse(string word, int ind, Node* root) {
        if(ind == word.size()) {
            return root->val;
        }
        char c = word[ind];
        if(c == '.') {
            for(int i = 0; i < 26; i++) {
                if(root->child[i] == NULL) continue;
                else if(traverse(word, ind + 1, root->child[i])) {
                    return true;
                }
            }
        } else {
            if(root->child[c - 'a'] == NULL) return false;
            return traverse(word, ind + 1, root->child[c - 'a']);
        }
        return false;
    }
    bool search(string word) {
        Node* node = root;
        return traverse(word, 0, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */