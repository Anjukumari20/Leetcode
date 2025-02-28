class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int i = 0, j = 0; // i for s, j for t
            while (j < t.length()) {
                if (i < s.length() && s[i] == t[j]) {
                    i++; // Move s pointer if match found
                }
                j++; // Always move t pointer
            }
            return i == s.length(); // If s pointer reaches the end, it is a subsequence
        }
    };