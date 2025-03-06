class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
              int left = 0, zeroCount = 0, maxLength = 0;
    
            for (int right = 0; right < nums.size(); right++) {
                if (nums[right] == 0) zeroCount++;
    
                // If more than 1 zero is encountered, move left pointer
                while (zeroCount > 1) {
                    if (nums[left] == 0) zeroCount--;
                    left++;
                }
    
                // Length of valid subarray (excluding one deletion)
                maxLength = max(maxLength, right - left);
            }
            return maxLength;
        }
    };