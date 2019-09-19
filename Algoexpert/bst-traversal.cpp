#include <vector>
using namespace std;

class BST {
  public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
    BST& insert(int val);
};

vector<int> inOrderTraverse(BST* tree, vector<int> array) {
  // Write your code here.
	if (!tree) return {};
	if (tree->left) array = inOrderTraverse(tree->left, array);
	array.push_back(tree->value);
	if (tree->right) array = inOrderTraverse(tree->right, array);
	return array;
}

vector<int> preOrderTraverse(BST* tree, vector<int> array) {
  // Write your code here.
	if (!tree) return {};
	array.push_back(tree->value);
	if (tree->left) array = preOrderTraverse(tree->left, array);
	if (tree->right) array = preOrderTraverse(tree->right, array);
	return array;
}

vector<int> postOrderTraverse(BST* tree, vector<int> array) {
  // Write your code here.
	if (!tree) return {};
	if (tree->left) array = postOrderTraverse(tree->left, array);
	if (tree->right) array = postOrderTraverse(tree->right, array);
	array.push_back(tree->value);
	return array;
}