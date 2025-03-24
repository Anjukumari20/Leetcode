class Solution {
    public:
        int countGoodNodes(TreeNode* node, int maxSoFar) {
            if (!node) return 0;
            
            int good = (node->val >= maxSoFar) ? 1 : 0;
            maxSoFar = max(maxSoFar, node->val);
            
            return good + countGoodNodes(node->left, maxSoFar) + countGoodNodes(node->right, maxSoFar);
        }
        
        int goodNodes(TreeNode* root) {
            return countGoodNodes(root, root->val);
        }
    };