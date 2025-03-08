class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int minOperations = k;
            int countW = 0;
            
            // Count white blocks in the first window of size k
            for (int i = 0; i < k; i++) {
                if (blocks[i] == 'W') countW++;
            }
            minOperations = countW;
            
            // Slide the window across the string
            for (int i = k; i < blocks.size(); i++) {
                if (blocks[i - k] == 'W') countW--;
                if (blocks[i] == 'W') countW++;
                
                minOperations = min(minOperations, countW);
            }
            
            return minOperations;
        }
    };
    