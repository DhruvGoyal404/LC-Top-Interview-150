// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            Node* prev = NULL;
            while(n--){
                Node* k = q.front();
                q.pop();
                if(prev == NULL) prev = k;
                else{
                    prev->next = k;
                    prev = k;
                }
                if(k->left) q.push(k->left);
                if(k->right) q.push(k->right);
            }
            prev->next = NULL;
        }
        return root;
    }
};