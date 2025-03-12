class Solution {
    public:
        int equalPairs(vector<vector<int>>& grid) {
            int n = grid.size();
            map<vector<int>, int> rowCount;
            int count = 0;
    
            // Store frequency of each row
            for (const auto& row : grid) {
                rowCount[row]++;
            }
    
            // Check columns against rowCount
            for (int j = 0; j < n; j++) {
                vector<int> col;
                for (int i = 0; i < n; i++) {
                    col.push_back(grid[i][j]);
                }
                if (rowCount.find(col) != rowCount.end()) {
                    count += rowCount[col]; // Multiply occurrences of row with matching columns
                }
            }
    
            return count;
        }
    };