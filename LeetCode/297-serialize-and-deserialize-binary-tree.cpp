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
    
    void preOrder(TreeNode* root, string& s) {
        if (!root) {
            s += "x,";
            return;
        }
        s += to_string(root->val);
        s += ',';
        preOrder(root->left, s);
        preOrder(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string toReturn = "";
        preOrder(root, toReturn);
        return toReturn;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if (n == 0) return NULL;
        vector<int> dVec;
        int i = 0;
        int j = 0;
        while (i < n) {
            if (data[j] == 'x') {
                dVec.push_back(INT_MIN);
                j += 2;
                i = j;
                continue;
            }
            if (data[j] == ',') {
                dVec.push_back(stoi(data.substr(i, j - i)));
                i = ++j;
            } else {
                j++;
            }
        }
        stack<pair<TreeNode*, int>> s;
        TreeNode* root = new TreeNode(dVec[0]);
        s.emplace(root, 0);
        for (int i = 1; i < dVec.size(); i++) { 
            TreeNode* p = nullptr;
            if (dVec[i] != INT_MIN) {
                p = new TreeNode(dVec[i]);
            }
            if (s.top().second == 0) {
                s.top().first->left = p;
                s.top().second = 1;
            } else if (s.top().second == 1) {
                s.top().first->right = p;
                s.pop();
            } 
            if (p) {
                s.emplace(p, 0);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));