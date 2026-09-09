// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0; i<size; i++){
                auto it = q.front();
                q.pop();
                temp.push_back(it->val);
                if(it->left!=NULL) q.push(it->left);
                if(it->right!=NULL) q.push(it->right);
            }
            result.push_back(temp);
        }
        return result;
    }
};