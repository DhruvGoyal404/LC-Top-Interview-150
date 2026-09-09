// https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                if(n==0) result.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return result;
    }
};