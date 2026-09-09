// https://leetcode.com/problems/validate-binary-search-tree/
class Solution {
public:
    bool check(TreeNode* root, long long mini, long long maxi){
        if(!root) return true;
        if(root->val <= mini || root->val >= maxi) return false;
        return check(root->left, mini, root->val) && check(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};