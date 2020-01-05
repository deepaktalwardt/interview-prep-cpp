class BST {
  public:
    int value;
    BST* left;
    BST* right;
  
    BST(int val);
    BST& insert(int val);
};

// O(n) time | O(d) space
bool validateBst(BST* tree, int minVal=INT_MIN, int maxVal=INT_MAX) {
  // Write your code here.
	if (!tree) return true;
	int val = tree->value;
	if (val >= minVal && val < maxVal) {
		return validateBst(tree->left, minVal, val) && validateBst(tree->right, val, maxVal);
	}
	return false;
}