// https://leetcode.com/problems/minimum-genetic-mutation/description/
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        if (bankSet.find(endGene) == bankSet.end()) return -1;
        queue<pair<string, int>> q; // {current_gene, steps}
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);
        while(!q.empty()){
            string tops = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (tops == endGene) return steps;
            for (int i = 0; i < 8; i++) {
                for (char c: {'A', 'C', 'G', 'T'}) {
                    if (tops[i] == c) continue; 
                    string next = tops.substr(0, i) + c + tops.substr(i+1);
                    if (bankSet.count(next) && !visited.count(next)) {
                        if (next == endGene) return steps + 1;
                        visited.insert(next);
                        q.push({next, steps + 1});
                    }
                }
            }
        }
        return -1;
    }
};