class Solution {
    public:
        int longestPath = 0;
    
        void Solve(TreeNode* &root, bool isLeft, int path){
            if(!root) return;
    
            // Update the maximum Path
            longestPath = max(longestPath, path);
    
            // if previously we took Left then we should add the path in rightPath
            if(isLeft){
                Solve(root->right, false, path+1);
                Solve(root->left, true, 1);
            }
    
            // if previously we took Right then we should add the path in leftPath
            else{
                Solve(root->left, true, path+1);
                Solve(root->right, false, 1);
            }
        }
    
        int longestZigZag(TreeNode* root) {
    
            // Go left if is available and pass isLeft true
            if(root->left){
                Solve(root->left, true, 1);
            }
            
            // Go left if is available and pass isLeft true
            if(root->right){
                Solve(root->right, false, 1);
            }
            
            return longestPath; 
        }
    };