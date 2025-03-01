
class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
    
            // Step 1: Process the array to double and set zeroes
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] == nums[i + 1] && nums[i] != 0) {
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
            }
    
            // Step 2: Move all zeroes to the end
            vector<int> result;
            for (int num : nums) {
                if (num != 0) result.push_back(num);
            }
    
            while (result.size() < n) {
                result.push_back(0);
            }
    
            return result;
        }
    };