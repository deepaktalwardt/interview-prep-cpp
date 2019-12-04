#include <vector>
using namespace std;

class BinaryTree {
  public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value);
    void insert(vector<int> values, int i = 0);
    void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree* tree) {
  // Write your code here.
	if (tree == nullptr) return;
	BinaryTree* tmp = tree->left;
	tree->left = tree->right;
	tree->right = tmp;
	invertBinaryTree(tree->left);
	invertBinaryTree(tree->right);
}
