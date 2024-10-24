/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
         while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }

        return dummy->next;
    }
     ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if( head==NULL || head->next == NULL){
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* rightHalf = middle->next;
        middle->next = nullptr;
         ListNode* left = sortList(head);
         ListNode* right = sortList(rightHalf);
         return merge(left, right);
    }
};
