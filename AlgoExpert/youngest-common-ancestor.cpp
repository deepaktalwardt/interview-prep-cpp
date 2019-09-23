#include <vector>
using namespace std;

class AncestralTree {
  public:
    char name;
    AncestralTree* ancestor;

    AncestralTree(char name) {
      this->name = name;
      this->ancestor = NULL;
    }
    
    void addAsAncestor(vector<AncestralTree*> descendants);
};

int depthOfDescendent(AncestralTree* top, AncestralTree* des) {
	int depth = 0;
	while (des != top) {
		des = des->ancestor;
		depth++;
	}
	return depth;
}

AncestralTree* getYoungestCommonAncestor(
  AncestralTree* topAncestor, 
  AncestralTree* descendantOne, 
  AncestralTree* descendantTwo
) {
  // Write your code here.
	int d1 = depthOfDescendent(topAncestor, descendantOne);
	int d2 = depthOfDescendent(topAncestor, descendantTwo);
	int diff = d1 < d2 ? d2 - d1 : d1 - d2;
	if (d1 < d2) {
		while (diff) {
			descendantTwo = descendantTwo->ancestor;
			diff--;
		}
	} else if (d1 > d2) {
		while (diff) {
			descendantOne = descendantOne->ancestor;
			diff--;
		}
	}
	while (descendantOne != descendantTwo) {
		descendantOne = descendantOne->ancestor;
		descendantTwo = descendantTwo->ancestor;
	}
	return descendantOne;
}