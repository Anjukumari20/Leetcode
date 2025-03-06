class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
                int n = grid.size();
            int N = n * n;
            vector<int> freq(N + 1, 0); // Frequency array (1-based index)
    
            int a = -1, b = -1; // Variables to store repeated and missing numbers
    
            // Count frequency of each number in the matrix
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    freq[grid[i][j]]++;
                }
            }
    
            // Identify repeated and missing numbers
            for (int num = 1; num <= N; num++) {
                if (freq[num] == 2) a = num; // Repeated number
                if (freq[num] == 0) b = num; // Missing number
            }
    
            return {a, b};
        }
    };