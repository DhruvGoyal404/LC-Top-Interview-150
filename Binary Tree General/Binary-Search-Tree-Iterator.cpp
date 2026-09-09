// https://leetcode.com/problems/binary-search-tree-iterator
class BSTIterator {
public:
    int i, n;
    vector<int> Arr;

    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        Arr.push_back(root->val);
        inorder(root->right);
    }

    BSTIterator(TreeNode* root) {
        i=0;
        inorder(root);
        n = Arr.size();
    }
    
    int next() {
        return Arr[i++];
    }
    
    bool hasNext() {
        return i<=n-1;
    }
};