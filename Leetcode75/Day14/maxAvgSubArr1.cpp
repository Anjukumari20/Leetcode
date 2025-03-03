class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            int n = nums.size();
            double maxSum = 0, windowSum = 0;
            
            // Compute the initial window sum
            for (int i = 0; i < k; i++) {
                windowSum += nums[i];
            }
            maxSum = windowSum;
    
            // Slide the window
            for (int i = k; i < n; i++) {
                windowSum += nums[i] - nums[i - k]; // Add new element, remove old element
                maxSum = max(maxSum, windowSum);
            }
    
            return maxSum / k;
        }
    };