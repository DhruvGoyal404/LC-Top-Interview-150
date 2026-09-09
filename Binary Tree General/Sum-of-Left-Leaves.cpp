// https://leetcode.com/problems/sum-of-left-leaves
class Solution {
public:
    int sum = 0;

    void solve(TreeNode* root, bool isLeft){
        if(!root) return;
        solve(root->left, true);
        if(root->left == NULL && root->right == NULL && isLeft) sum+=root->val;
        solve(root->right, false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        solve(root, false);
        return sum;
    }
};