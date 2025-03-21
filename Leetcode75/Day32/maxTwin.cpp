
class Solution {
    public:
        int pairSum(ListNode* head) {
            // Step 1: Find middle of the list
            ListNode* slow = head, *fast = head;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            // Step 2: Reverse second half
            ListNode* prev = NULL, *curr = slow, *nextNode = NULL;
            while (curr) {
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
    
            // Step 3: Compute max twin sum
            int maxSum = 0;
            ListNode* first = head, *second = prev;
            while (second) {
                maxSum = max(maxSum, first->val + second->val);
                first = first->next;
                second = second->next;
            }
    
            return maxSum;
        }
    };