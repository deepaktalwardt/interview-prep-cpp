#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  LinkedList *getNthNode(int n);
};

LinkedList* findLoop(LinkedList* head) {
	LinkedList* slow = head;
	LinkedList* fast = head;
	while (true) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			break;
		}
	}
	fast = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
