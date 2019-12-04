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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* dummy = &head;
        int carry = 0;
        while (l1 && l2) {
            int next_val = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            dummy->next = new ListNode(next_val);
            l1 = l1->next;
            l2 = l2->next;
            dummy = dummy->next;
        }
        
        if (l1 && !l2) {
            while (l1) {
                int next_val = (l1->val + carry) % 10;
                carry = (l1->val + carry) / 10;
                dummy->next = new ListNode(next_val);
                l1 = l1->next;
                dummy = dummy->next;
            }
        } else if (!l1 && l2) {
            while (l2) {
                int next_val = (l2->val + carry) % 10;
                carry = (l2->val + carry) / 10;
                dummy->next = new ListNode(next_val);
                l2 = l2->next;
                dummy = dummy->next;
            }
        }
        
        if (carry) {
            dummy->next = new ListNode(carry);
            dummy = dummy->next;
        }
        
        
        return head.next;
    }
};