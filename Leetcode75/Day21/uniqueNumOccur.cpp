class Solution {
    public:
        bool uniqueOccurrences(vector<int>& arr) {
            unordered_map<int, int> freqMap;
            unordered_set<int> occurrences;
    
            // Count occurrences of each number
            for (int num : arr) {
                freqMap[num]++;
            }
    
            // Check if occurrences are unique
            for (const auto& pair : freqMap) {
                if (!occurrences.insert(pair.second).second) {
                    return false;
                }
            }
    
            return true;
        }
    };