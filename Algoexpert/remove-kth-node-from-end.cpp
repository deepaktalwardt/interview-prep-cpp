#include <vector>
using namespace std;

class LinkedList {
  public:
    int value;
    LinkedList* next;

    LinkedList(int value);
    void addMany(vector<int> values);
    vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList* head, int k) {
  // Write your code here.
	int counter = -k;
	LinkedList* p0 = head;
	LinkedList* p1 = head->next;
	LinkedList* p2 = head;
	while(p2 != nullptr) {
		if (counter > 0) {
			p0 = p1;
			p1 = p1->next;
		}
		counter++;
		p2 = p2->next;
	}
	
	if (counter == 0) {
		head->value = head->next->value;
		head->next = head->next->next;
		return;
	}
	
	p0->next = p1->next;
}