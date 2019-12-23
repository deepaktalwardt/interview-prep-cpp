#include <iostream>
#include <cmath>
#include <float.h>

using namespace std;

class BST {
  public:
    int value;
    BST* left;
    BST* right;

    BST(int val);
    BST& insert(int val);
};

int findClosestValueInBst(BST* tree, int target);
int findClosestValueInBstHelper(BST* tree, int target, double closest);

int findClosestValueInBst(BST* tree, int target) {
  // Write your code here.
	return findClosestValueInBstHelper(tree, target, DBL_MAX);
}

// Recursive
// Average: O(log n) time | O(log n) space
// Worst: O(n) time | O(n) space
int findClosestValueInBstHelper(BST* tree, int target, double closest) {
	if (abs(closest - target) > abs(tree->value - target)) {
		closest = tree->value;
		if (target == tree->value) { // Early stop if target equal to current value
			return (int) closest;
		}
	}
	if (target < tree->value && tree->left != NULL) {
		return findClosestValueInBstHelper(tree->left, target, closest);
	} else if (target > tree->value && tree->right != NULL) {
		return findClosestValueInBstHelper(tree->right, target, closest);
	} else {
		return (int) closest;
	}
}

// Iterative
// Average: O(log n) time | O(1) space
// Worst: O(n) time | O(1) space
int findClosestValueInBstHelper(BST* tree, int target, double closest) {
	while (tree != NULL) {
		if (abs(closest - target) > abs(tree->value - target)) {
			closest = tree->value;
		}
		if (target < tree->value) {
			tree = tree->left;
		} else if (target > tree->value) {
			tree = tree->right;
		} else {
			break;
		}
	}
	return (int) closest;
}