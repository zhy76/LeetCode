class Solution {
public:
    struct Node {
        bool val;
        vector<Node*> child;
        Node() {
            val = false;
            child = vector<Node*>(26, NULL);
        }
    };

    void insert(Node* root, string word) {
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

    string shortestPrefix(Node* root, string word) {
        Node* node = root;
        int len = 0;
        for(char c : word) {
            int ind = c - 'a';
            if(node->child[ind] == NULL) break;
            len++;
            if(node->child[ind]->val) return word.substr(0, len);
            node = node->child[ind];
        }
        return word;
    }    

    string replaceWords(vector<string>& dictionary, string sentence) {
        Node* root = new Node();
        for(auto dic : dictionary) {
            insert(root, dic);
        }
        vector<string> words;
        string tmp = "";
        for(int i = 0; i < sentence.length(); i++) {
            char c = sentence[i];
            if(c != ' ') tmp += c;
            else {
                words.push_back(tmp);
                tmp = "";
            }
        }
        words.push_back(tmp);
        string res = "";
        for(int i = 0; i< words.size(); i++) {
            // string prefix = words[i];
            string prefix = shortestPrefix(root, words[i]);
            res += prefix;
            if(i != words.size() - 1) res += " ";
        }
        return res;
    }
};