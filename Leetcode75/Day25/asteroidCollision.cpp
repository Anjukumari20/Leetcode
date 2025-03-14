class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            stack<int> st;
            
            for (int ast : asteroids) {
                bool destroyed = false;
                
                while (!st.empty() && ast < 0 && st.top() > 0) {
                    if (abs(st.top()) < abs(ast)) {
                        st.pop(); // The top asteroid is destroyed
                    } else if (abs(st.top()) == abs(ast)) {
                        st.pop(); // Both asteroids destroy each other
                        destroyed = true;
                        break;
                    } else {
                        destroyed = true;
                        break;
                    }
                }
                
                if (!destroyed) {
                    st.push(ast);
                }
            }
            
            vector<int> result(st.size());
            for (int i = result.size() - 1; i >= 0; --i) {
                result[i] = st.top();
                st.pop();
            }
            
            return result;
        }
    };
    