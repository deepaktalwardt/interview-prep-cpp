#include <vector>
using namespace std;

class BinaryTree {
  public:
    int value;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
};

struct sums {
	int branchSum = INT_MIN;
	int runningSum = INT_MIN;
	sums(int b, int r) : branchSum(b), runningSum(r) {}
};

sums findMaxPath(BinaryTree* tree) {
	if (!tree) return sums(0, 0);
	sums ls = findMaxPath(tree->left);
	sums rs = findMaxPath(tree->right);
	int maxPathBranch = max(ls.branchSum, rs.branchSum);
	maxPathBranch = max(maxPathBranch + tree->value, tree->value);
	int maxSumAsTriangle = max(maxPathBranch, ls.branchSum + rs.branchSum + tree->value);
	int maxRunningSum = max(maxSumAsTriangle, max(ls.runningSum, rs.runningSum));
	return sums(maxPathBranch, maxRunningSum);
}

int maxPathSum(BinaryTree tree) {
  // Write your code here.
	sums result = findMaxPath(&tree);
	return result.runningSum;
}