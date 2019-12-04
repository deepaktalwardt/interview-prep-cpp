class SolutionRecursive {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l2, l1->next);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }     
    }
};

class SolutionIterative {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        ListNode resultHead(0);
        ListNode* resultTail_p = &resultHead;
        
        while (l1 != NULL && l2 != NULL)  {
            if (l1->val <= l2->val) {
                resultTail_p->next = l1;
                l1 = l1->next;
            } else {
                resultTail_p->next = l2;
                l2 = l2->next;
            }
            resultTail_p = resultTail_p->next;
        }
        resultTail_p->next = (l1 != NULL) ? l1 : l2;
        return resultHead.next;
    }
};