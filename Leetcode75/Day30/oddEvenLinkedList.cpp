class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            if (!head || !head->next) return head; // If list is empty or has only one node, return as is
            
            ListNode* odd = head; // Pointer to odd indexed nodes
            ListNode* even = head->next; // Pointer to even indexed nodes
            ListNode* evenHead = even; // Store the starting point of even list
            
            while (even && even->next) {
                odd->next = even->next; // Link current odd node to the next odd node
                odd = odd->next; // Move odd pointer forward
                
                even->next = odd->next; // Link current even node to the next even node
                even = even->next; // Move even pointer forward
            }
            
            odd->next = evenHead; // Connect the end of odd list to the head of even list
            return head;
        }
    };