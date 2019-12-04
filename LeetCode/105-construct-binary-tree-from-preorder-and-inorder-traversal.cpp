/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        int rootVal = preorder[0];
        if (preorder.size() == 1) {
            return new TreeNode(rootVal);
        }
        int i = 0;
        for (; i < inorder.size(); i++) {
            if (rootVal == inorder[i]) break;
        }
        vector<int> leftPreorder = {preorder.begin() + 1, preorder.begin() + 1 + i};
        vector<int> rightPreorder = {preorder.begin() + 1 + i, preorder.end()};
        vector<int> leftInorder = {inorder.begin(), inorder.begin() + i};
        vector<int> rightInorder = {inorder.begin() + i + 1, inorder.end()};
        
        TreeNode* currNode = new TreeNode(rootVal);
        currNode->left = buildTree(leftPreorder, leftInorder);
        currNode->right = buildTree(rightPreorder, rightInorder);
        return currNode;
    }
};