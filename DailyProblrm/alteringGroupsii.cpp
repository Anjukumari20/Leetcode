
class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            int count = 0;
            int validLength = 1;  // Length of the current alternating sequence
    
            // Check for the first k elements
            for (int i = 1; i < n * 2; i++) {  
                if (colors[i % n] != colors[(i - 1) % n]) {
                    validLength++;
                } else {
                    validLength = 1; // Reset on failure
                }
    
                // If a valid segment of length k is formed
                if (validLength >= k) {
                    count++;
                }
    
                // Only process n elements since it's circular
                if (i >= n + k - 2) break;  
            }
    
            return count;
        }
    };
    