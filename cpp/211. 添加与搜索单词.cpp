class WordDictionary {
private:
    bool val;
    vector<WordDictionary*> child;
public:
    WordDictionary() {
        val = false;
        child = vector<WordDictionary*>(26, NULL);
    }
    
    void addWord(string word) {
        WordDictionary* node = this;
        for(char c:word) {
            if(node->child[c - 'a'] == NULL) {
                node->child[c - 'a'] = new WordDictionary();
            }
            node = node->child[c - 'a'];
        }
        node->val = true;
    }
    
    bool search(string word) {
        WordDictionary* node = this;
        return traverse(word, 0, node);
    }

    bool traverse(string word, int ind, WordDictionary* root) {
        if(ind == word.size()) {
            return root->val;
        }
        char c = word[ind];
        if(c>='a' && c<='z') {
            if(root->child[c-'a'] == NULL) {
                return false;
            }
            return traverse(word, ind+1, root->child[c-'a']);
        } else {
            for(int i=0; i<26; i++) {
                if(root->child[i] != NULL && traverse(word, ind+1, root->child[i])) {
                    return true;
                }
            }
        }
        return false;  
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */