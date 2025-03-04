class Solution {
    public:
        int maxVowels(string s, int k) {
             unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
            int maxCount = 0, currentCount = 0;
    
            // Count vowels in the first window of size k
            for (int i = 0; i < k; i++) {
                if (vowels.count(s[i])) currentCount++;
            }
            maxCount = currentCount;
    
            // Slide the window across the string
            for (int i = k; i < s.length(); i++) {
                if (vowels.count(s[i])) currentCount++;     // Add new character
                if (vowels.count(s[i - k])) currentCount--; // Remove old character
                maxCount = max(maxCount, currentCount);
            }
    
            return maxCount;
        }
    };