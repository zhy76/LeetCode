class Solution {
public:
    struct Trie{
        bool val;
        vector<Trie*> child;
        Trie() {
            val = false;
            child = vector<Trie*>(26, NULL);
        }
    };

    void insert(Trie* root, string word) {
        for(char c:word) {
            if(root->child[c - 'a'] == NULL) {
                root->child[c - 'a'] = new Trie();
            }
            root = root->child[c - 'a'];
        }
        root->val = true;
    }

    string getShortestPrefix(Trie* root, string word) {
        if(root == NULL) return "";
        string res;
        for(char c: word) {
            root = root->child[c-'a'];
            if(root == NULL) return word;
            if(root != NULL) {
                res += c;
                if(root->val) break;
            }
        }
        return res;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();
        for(string word: dictionary) {
            insert(root, word);
        }
        vector<string> words;
        string tmp;
        for(char c:sentence) {
            if(c != ' ') {
                tmp += c;
            } else {
                words.push_back(tmp);
                tmp = "";
            }
        }
        if(tmp.size() != 0) {
            words.push_back(tmp);
        }
        for(int i=0; i<words.size(); i++) {
            words[i] = getShortestPrefix(root, words[i]);
        }
        string ans;
        for(int i=0; i<words.size(); i++) {
            if(i != words.size() - 1) {
                ans = ans+words[i]+" ";
            } else ans += words[i];
        }
        return ans;
    }
};