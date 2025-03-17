class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int, int> freq;
            
            // Count frequency of each number
            for (int num : nums) {
                freq[num]++;
            }
            
            // Check if every number appears an even number of times
            for (const auto& entry : freq) {
                if (entry.second % 2 != 0) {
                    return false;
                }
            }
            
            return true;
        }
    };
    