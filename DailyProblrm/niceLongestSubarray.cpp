class Solution {
    public:
        int longestNiceSubarray(std::vector<int>& nums) {
            int left = 0, maxLength = 0, bitwiseAND = 0;
            
            for (int right = 0; right < nums.size(); ++right) {
                while ((bitwiseAND & nums[right]) != 0) {
                    bitwiseAND ^= nums[left];
                    left++;
                }
                bitwiseAND |= nums[right];
                maxLength = std::max(maxLength, right - left + 1);
            }
            
            return maxLength;
        }
    };