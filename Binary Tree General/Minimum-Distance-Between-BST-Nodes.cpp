// https://leetcode.com/problems/minimum-distance-between-bst-nodes/
class Solution {
public:
    TreeNode* prev = NULL;
    bool prevExists = false;
    int ans = INT_MAX;

    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        if(prevExists) ans = min(ans, root->val - prev->val);
        prev = root;
        prevExists = true;
        solve(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        solve(root);
        return ans;
    }

    int minDiffInBST(TreeNode* root) {
        return getMinimumDifference(root);
    }
};