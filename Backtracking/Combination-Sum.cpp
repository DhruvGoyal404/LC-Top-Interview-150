// https://leetcode.com/problems/combination-sum/
class Solution {
public:
    void helper(int idx, int target, vector<int> &test, vector<vector<int>> &result, vector<int> &candidates){
        if(idx == candidates.size()){
            if(target == 0) result.push_back(test);
            return;
        } // 2 3 6 7, target 7 , 2 2 3, [{1, 1}, 1, 0, 0}]
        if(candidates[idx]<=target && idx < candidates.size()){
            test.push_back(candidates[idx]); // take case -> call recursion -> not take case
            helper(idx, target - candidates[idx], test, result, candidates);
            test.pop_back(); // backtracking
        }
        helper(idx + 1, target, test, result, candidates); // not take case
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> test;
        helper(0, target, test, result, candidates);
        return result;
    }
};