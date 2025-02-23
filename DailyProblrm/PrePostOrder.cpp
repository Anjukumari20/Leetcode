class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            unordered_map<int, int> postIndex;
            for (int i = 0; i < postorder.size(); i++) {
                postIndex[postorder[i]] = i;
            }
            int preIndex = 0;
            return construct(preorder, postorder, postIndex, preIndex, 0, postorder.size() - 1);
        }
    
    private:
        TreeNode* construct(vector<int>& preorder, vector<int>& postorder, unordered_map<int, int>& postIndex, int& preIndex, int left, int right) {
            if (left > right || preIndex >= preorder.size()) return nullptr;
            
            TreeNode* root = new TreeNode(preorder[preIndex++]);
            if (left == right) return root;
            
            int postLeftIndex = postIndex[preorder[preIndex]];
            root->left = construct(preorder, postorder, postIndex, preIndex, left, postLeftIndex);
            root->right = construct(preorder, postorder, postIndex, preIndex, postLeftIndex + 1, right - 1);
            
            return root;
        }
    };