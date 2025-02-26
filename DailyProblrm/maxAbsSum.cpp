class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
               int maxSum = 0, minSum = 0, currentMax = 0, currentMin = 0;
            for (int num : nums) {
                currentMax = max(0, currentMax + num);
                maxSum = max(maxSum, currentMax);
                currentMin = min(0, currentMin + num);
                minSum = min(minSum, currentMin);
            }
            return max(maxSum, abs(minSum));
        }
    };