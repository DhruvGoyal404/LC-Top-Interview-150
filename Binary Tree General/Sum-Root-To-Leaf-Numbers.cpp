// https://leetcode.com/problems/sum-root-to-leaf-numbers/
class Solution {
public:
    void preorder(TreeNode* root, int &sum, int count){
        if(!root) return;
        count = (count*10)+root->val;
        if(!root->left && !root->right){
            sum+=count;
            count/=10;
        }
        preorder(root->left, sum, count);
        preorder(root-> right, sum, count);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0, count = 0;
        preorder(root, sum, count);
        return sum;
    }
};