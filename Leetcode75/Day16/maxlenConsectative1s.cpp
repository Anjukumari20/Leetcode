class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int left = 0, right = 0, maxLen = 0, zeroCount = 0;
            
            while (right < nums.size()) {
                // If we encounter a zero, increase the zero counter
                if (nums[right] == 0) {
                    zeroCount++;
                }
    
                // If the zero count exceeds k, shrink the window from the left
                while (zeroCount > k) {
                    if (nums[left] == 0) {
                        zeroCount--;
                    }
                    left++; // Move the left pointer forward
                }
    
                // Update the maximum window size
                maxLen = max(maxLen, right - left + 1);
                right++; // Expand the window
            }
            
            return maxLen;
        }
    };