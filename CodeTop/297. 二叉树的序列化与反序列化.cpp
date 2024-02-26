/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string res;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        seria(root);
        return res;
    }
    void seria(TreeNode* root) {
        if(root == NULL) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ",";
        seria(root->left);
        seria(root->right);
    }

    vector<string> strs;
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string tmp = "";
        for(auto c : data) {
            if(c == ',') {
                strs.push_back(tmp);
                tmp = "";
                continue;
            }
            tmp += c;
        }
        return deserialize();
    }

    TreeNode* deserialize() {
        if(strs.empty()) return NULL;
        string first = strs.front();
        strs.erase(strs.begin());
        if(first == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(first));
        root->left = deserialize();
        root->right = deserialize();
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));