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
    ListNode* reverselinkedlist(ListNode* head){
        if(head==nullptr || head->next == nullptr){
            return head;
        }
        ListNode* newhead = reverselinkedlist(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr || head->next == nullptr){
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr ){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newHead = reverselinkedlist(slow->next); 
        ListNode* first = head;
        ListNode* second = newHead;

        while(second!=nullptr){
            if(first->val!=second->val){
                reverselinkedlist(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reverselinkedlist(newHead);
        return true;

    }
};
