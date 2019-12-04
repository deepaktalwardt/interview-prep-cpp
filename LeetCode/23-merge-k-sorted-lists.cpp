#include <queue>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> 
            min_heap([](ListNode* a, ListNode* b) { return a->val > b->val; });
        
        for (ListNode* list : lists) {
            ListNode* b = list;
            if (b) {
                min_heap.emplace(b);
            }
        }
        
        ListNode head = ListNode(0);
        ListNode* dummy = &head;
        
        while (!empty(min_heap)) {
            ListNode* top = min_heap.top();
            dummy->next = top;
            min_heap.pop();
            if (top->next != nullptr) {
                min_heap.emplace(top->next);
            }
            dummy = dummy->next;
        }
        
        return head.next;
    }
};