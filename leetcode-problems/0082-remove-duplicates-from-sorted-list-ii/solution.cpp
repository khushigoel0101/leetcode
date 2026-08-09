class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        while (head && head->next && head->val == head->next->val) {
            int dupVal = head->val;
            while (head && head->val == dupVal) {
                head = head->next;
            }
        }
        if (!head) return nullptr; 
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast) {
            if (fast->next && fast->val == fast->next->val) {
                int dupVal = fast->val;
                while (fast && fast->val == dupVal) {
                    fast = fast->next;
                }
                slow->next = fast;
            } else {
                slow = fast;
                fast = fast->next;
            }
        }
        return head;
    }
};
