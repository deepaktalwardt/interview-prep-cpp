class Solution {
public:
    bool isIdentical(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr) {
            return true;
        } else if (a != nullptr && b != nullptr) {
            return a->val == b->val && isIdentical(a->left, b->left) && isIdentical(a->right, b->right);
        } else {
            return false;
        }
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) {
            return true;
        } 
        if (s == nullptr || t == nullptr) {
            return false;
        }
        if (s->val == t->val) {
            return isIdentical(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};