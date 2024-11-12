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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         if (!headA || !headB) return NULL;

        ListNode* a = headA;
        ListNode* b = headB;

        // Traverse both lists. When a pointer reaches the end of a list,
        // start it at the beginning of the other list.
        while (a != b) {
            a = (a != NULL) ? a->next : headB;
            b = (b != NULL) ? b->next : headA;
        }

        // Both pointers will either meet at the intersection point or at NULL.
        return a;
    }
};

