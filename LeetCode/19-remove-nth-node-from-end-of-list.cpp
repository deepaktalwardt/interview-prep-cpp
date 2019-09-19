/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int counter = -n;
        ListNode* toReturn = head;
        ListNode* p0 = head;
        ListNode* p1 = head->next;
        ListNode* p2 = head;
        while (p2 != nullptr) {
            if (counter > 0) {
                p0 = p1;
                p1 = p1->next;
            }
            counter++;
            p2 = p2->next;
        }
        if (counter == 0) {
            if (head->next != nullptr) {
                head->val = head->next->val;
                head->next = head->next->next;
                return toReturn;
            } else {
                return nullptr;
            }
        }
        p0->next = p1->next;
        return toReturn;
    }
};