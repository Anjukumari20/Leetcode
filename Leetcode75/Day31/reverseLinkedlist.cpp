class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            
            while (curr != nullptr) {
                ListNode* nextNode = curr->next; // Store next node
                curr->next = prev;  // Reverse the link
                prev = curr; // Move prev to current
                curr = nextNode; // Move to next node
            }
            
            return prev; // New head of the reversed list
        }
    };
    