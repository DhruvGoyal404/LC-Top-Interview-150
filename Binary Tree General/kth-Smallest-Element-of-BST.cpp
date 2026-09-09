// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
class Solution {
public:
    int solve(TreeNode* root, int k, int &value){
        if(!root) return -1;
        int left = solve(root->left, k, value);
        if(left != -1) return left;
        value++;
        if(value == k) return root->val;
        return solve(root->right, k, value);
    }

    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int value = 0;
        return solve(root, k, value);
    }
};