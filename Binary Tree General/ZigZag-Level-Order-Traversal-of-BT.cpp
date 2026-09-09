// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
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
            if(level % 2 != 0) reverse(temp.begin(), temp.end());
            result.push_back(temp);
            level++;
        }
        return result;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return levelOrder(root);
    }
};