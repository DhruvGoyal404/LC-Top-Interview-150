// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
class Solution {
public:
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int start, int end, int &idx){
        if(start > end) return nullptr;
        int rootVal = postorder[idx];
        int i = start;
        for(; i<=end; i++){
            if(inorder[i] == rootVal) break;
        }
        idx--;
        TreeNode* root = new TreeNode(rootVal);
        root->right = solve(inorder, postorder, i+1, end, idx);
        root->left = solve(inorder, postorder, start, i-1, idx);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int idx = n-1;
        return solve(inorder, postorder, 0, n-1, idx);
    }
};