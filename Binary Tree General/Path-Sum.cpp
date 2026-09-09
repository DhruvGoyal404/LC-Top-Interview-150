// https://leetcode.com/problems/path-sum/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(root->left == NULL && root->right == NULL){
            if(targetSum == root->val) return true;
        }
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};