/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Clone nodes and insert them next to their original counterparts
        Node* curr = head;
        while (curr) {
            Node* cloned = new Node(curr->val);
            cloned->next = curr->next;
            curr->next = cloned;
            curr = cloned->next;
        }

        // Step 2: Assign random pointers for the cloned nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next; // Move to the next original node
        }

        // Step 3: Separate the cloned list from the original list
        Node* dummy = new Node(0); // Dummy node for the new list
        Node* copyTail = dummy;
        curr = head;
        while (curr) {
            Node* cloned = curr->next;
            curr->next = cloned->next; // Restore the original list
            copyTail->next = cloned;  // Build the new list
            copyTail = cloned;
            curr = curr->next; // Move to the next original node
        }

        return dummy->next; // Head of the new list
    }
};

