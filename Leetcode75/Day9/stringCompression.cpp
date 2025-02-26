class Solution {
    public:
        int compress(vector<char>& chars) {
             int n = chars.size(), index = 0;
            for (int i = 0; i < n;) {
                char currentChar = chars[i];
                int count = 0;
                while (i < n && chars[i] == currentChar) {
                    count++;
                    i++;
                }
                chars[index++] = currentChar;
                if (count > 1) {
                    string countStr = to_string(count);
                    for (char c : countStr) {
                        chars[index++] = c;
                    }
                }
            }
            return index;
        }
    };