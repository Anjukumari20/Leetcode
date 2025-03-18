class Solution {
    public:
        ListNode* deleteMiddle(ListNode* head) {
            if (!head || !head->next) return nullptr; // If there's only one node, return nullptr
            
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = nullptr;
            
            // Use slow and fast pointer approach to find middle
            while (fast && fast->next) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            
            // Delete the middle node
            prev->next = slow->next;
            delete slow;
            
            return head;
        }
    };