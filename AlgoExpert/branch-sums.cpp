using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};

vector<int> branchSums(BinaryTree *root) {
  // Write your code here.
	if (!root->left && !root->right) {
		return {root->value};
	}
	vector<int> result;
	if (root->left) {
		vector<int> leftBranches = branchSums(root->left);
		result.insert(result.end(), leftBranches.begin(), leftBranches.end());
	}
	if (root->right) {
		vector<int> rightBranches = branchSums(root->right);
		result.insert(result.end(), rightBranches.begin(), rightBranches.end());
	}
	for (int i = 0; i < result.size(); i++) {
		result[i] += root->value;
	}
	return result;
}