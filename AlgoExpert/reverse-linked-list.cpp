using namespace std;

class LinkedList {
  public:
    int value;
    LinkedList* next;

    LinkedList(int value) {
      this->value = value;
    }
};

LinkedList* reverseLinkedList(LinkedList* head) {
  // Write your code here.
	LinkedList* p1 = nullptr;
	LinkedList* p2 = head;
	while (p2 != nullptr) {
		LinkedList* p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
	return p1;
}