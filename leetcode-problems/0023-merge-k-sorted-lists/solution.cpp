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
    struct compare{
        bool operator()(const ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
         priority_queue<ListNode* , vector<ListNode*>, compare>pq;

         for(ListNode* head : lists){
            if(head!=nullptr){
                pq.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(!pq.empty()){
            ListNode* smallestNode = pq.top();
            pq.pop();
            tail->next = smallestNode;
            tail = tail->next;

            if(smallestNode->next!=nullptr){
                pq.push(smallestNode->next);
            }
        }

        return dummy.next;

    }
};
