class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n = arr.size();
            unordered_map<int, int> index;
            vector<vector<int>> dp(n, vector<int>(n, 2));
            int maxLength = 0;
    
            for (int i = 0; i < n; i++) {
                index[arr[i]] = i;
            }
    
            for (int j = 1; j < n; j++) {
                for (int i = 0; i < j; i++) {
                    int x = arr[j] - arr[i];
                    if (index.count(x) && index[x] < i) {
                        int k = index[x];
                        dp[i][j] = dp[k][i] + 1;
                        maxLength = max(maxLength, dp[i][j]);
                    }
                }
            }
    
            return maxLength >= 3 ? maxLength : 0;
        }
    };
    