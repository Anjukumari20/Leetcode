

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
               stack<TreeNode*> st;  
                int i = 0;
                while (i < traversal.size()) {
                    int level = 0;
                    while (i < traversal.size() && traversal[i] == '-') {
                        level++;
                        i++;
                    }
                    
                    int val = 0;
                    while (i < traversal.size() && isdigit(traversal[i])) {
                        val = val * 10 + (traversal[i] - '0');
                        i++;
                    }
                    
                    TreeNode* node = new TreeNode(val);
                    
                    while (st.size() > level) {
                        st.pop();
                    }
                    
                    if (!st.empty()) {
                        if (st.top()->left == nullptr)
                            st.top()->left = node;
                        else
                            st.top()->right = node;
                    }
                    
                    st.push(node);
                }
                
                while (st.size() > 1) {
                    st.pop();
                }
                
                return st.top();
            
        }
    };