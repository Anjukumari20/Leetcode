
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int count[3] = {0, 0, 0};  // Frequency of 'a', 'b', and 'c'
            int l = 0, total = 0;
            
            for (int r = 0; r < s.size(); r++) {
                count[s[r] - 'a']++;  // Increase frequency of current character
                
                while (count[0] > 0 && count[1] > 0 && count[2] > 0) {  // Valid substring
                    total += s.size() - r;  // Count substrings ending at or after `r`
                    count[s[l] - 'a']--;  // Shrink window from the left
                    l++;  
                }
            }
            
            return total;
        }
    };
    