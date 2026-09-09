// https://leetcode.com/problems/maximum-depth-of-binary-tree/
class Solution {
public:
    int depth(TreeNode* root){
        if(!root) return 0;
        int k = depth(root->left);
        int p = depth(root->right);
        return 1+max(k, p);
    }

    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return depth(root);
    }
};