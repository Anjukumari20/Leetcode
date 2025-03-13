class Solution {
    public:
        string removeStars(string s) {
            stack<char> st;
            for (char c : s) {
                if (c == '*') {
                    if (!st.empty()) {
                        st.pop(); // Remove the last added character
                    }
                } else {
                    st.push(c);
                }
            }
            
            // Construct the result from the stack
            string result;
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }
            reverse(result.begin(), result.end());
            return result;
        }
    };