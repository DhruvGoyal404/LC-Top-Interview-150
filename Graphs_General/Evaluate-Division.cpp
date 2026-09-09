// https://leetcode.com/problems/evaluate-division/
class Solution {
public:
    void dfs(const string &src, const string &current, double product, unordered_set<string> &visited, unordered_map<string, vector<pair<string,double>>> &adj, unordered_map<string, unordered_map<string,double>> &ratio){
        if(visited.find(current) != visited.end()) return;
        ratio[src][current] = product;
        visited.insert(current);
        for(auto &[neighbour, weight] : adj[current]) if(visited.find(neighbour) == visited.end()) dfs(src, neighbour, product * weight, visited, adj, ratio);
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string,double>>> adj;
        for(int i=0; i<equations.size(); i++){
            string u = equations[i][0];
            string v = equations[i][1];
            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1.0 / values[i]});
        }
        unordered_map<string, unordered_map<string,double>> ratio;
        for (auto &[src, neighbors] : adj) {
            unordered_set<string> visited;
            dfs(src, src, 1.0, visited, adj, ratio); // original variable (numerator), changing denominator
        }  
        vector<double> output;
        for(int i=0; i<queries.size(); i++){
            string u = queries[i][0], v = queries[i][1];
            if(ratio.find(u) != ratio.end()){
                if(ratio[u].find(v) != ratio[u].end()){
                    output.push_back(ratio[u][v]);
                }
                else output.push_back(-1.0);
            }
            else output.push_back(-1.0);
        }
        return output;
    }
};