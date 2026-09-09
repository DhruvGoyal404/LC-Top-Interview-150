// https://leetcode.com/problems/average-of-levels-in-binary-tree/
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> output;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int div = n;
            long long sum = 0;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            output.push_back(sum/(div*1.0));
        }
        return output;
    }
};