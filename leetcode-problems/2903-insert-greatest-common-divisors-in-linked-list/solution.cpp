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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* current = head;
        while (current && current->next) {
            int gcd_value = std::gcd(current->val, current->next->val);
            ListNode* new_node = new ListNode(gcd_value);
            new_node->next = current->next;
            current->next = new_node;
            current = current->next->next;
        }
        return head;
    }
};
