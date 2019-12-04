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
    int maxSum = INT_MIN;
    
    int maxGain(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int leftMax = max(maxGain(root->left), 0);
        int rightMax = max(maxGain(root->right), 0);
        int tempSum = leftMax + rightMax + root->val;
        maxSum = maxSum < tempSum? tempSum : maxSum;
        return root->val + max(leftMax, rightMax);
    }
    
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};