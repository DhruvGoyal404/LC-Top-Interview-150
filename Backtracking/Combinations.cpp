// https://leetcode.com/problems/combinations/
class Solution {
public:
    void backtrack(int start, int n, int k, vector<int> &path, vector<vector<int>> &result){
        if(path.size() == k){
            result.push_back(path);
            return;
        }

        for(int i = start; i<=n; i++){
            path.push_back(i); // path -> 1
            backtrack(i+1, n, k, path, result);
            path.pop_back(); // backtrack step
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(1, n, k, path, result);
        return result;
    }
};
