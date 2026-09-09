// https://leetcode.com/problems/clone-graph/
class Solution {
public:
    unordered_map<Node*, Node*> mp;

    void DFS(Node* node, Node* clone_node){
        for(Node* n: node->neighbors){
            if(mp.find(n) == mp.end()){
                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(mp[n]);
                DFS(n, clone);
            } else clone_node->neighbors.push_back(mp[n]);
        }
    }

    void BFS(queue<Node*> &que){
        while(!que.empty()){
            Node* node = que.front();
            Node* clone_node = mp[node];
            que.pop();

            for(Node* n: node->neighbors){
                if(mp.find(n) == mp.end()){
                    Node* clone = new Node(n->val);
                    mp[n] = clone;
                    clone_node->neighbors.push_back(clone);
                    que.push(n);
                } else clone_node->neighbors.push_back(mp[n]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        // clone the given node
        Node* clone_node = new Node(node->val);

        // clone its neighbors and recursively their neighbors, but if a node reappears, then we need to access that cloned node, so, store them in a map<Node*, Node*>
        mp[node] = clone_node;
        // DFS(node, clone_node);
        queue<Node*> que;
        que.push(node);
        BFS(que);
        return clone_node;
    }
};