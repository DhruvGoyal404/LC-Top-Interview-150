// https://leetcode.com/problems/symmetric-tree/
class Solution {
public:
    bool symmetric(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if((left && !right) || (!left && right)) return false;
        if(left->val != right->val) return false;
        return symmetric(left->left, right->right) && symmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return symmetric(root->left, root->right);
    }
};