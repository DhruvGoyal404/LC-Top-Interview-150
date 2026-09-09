// https://leetcode.com/problems/course-schedule/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++){
            int u = prerequisites[i][1], v = prerequisites[i][0];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) if (inDegree[i] == 0) q.push(i);
        int check = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            check++;
            for(int v: adj[u]){
                inDegree[v]--;
                if (inDegree[v] == 0) q.push(v);
            }
        }
        if (check != numCourses) return false;
        return true; 
    }
};