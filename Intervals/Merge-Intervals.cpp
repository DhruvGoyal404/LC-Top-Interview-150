// https://leetcode.com/problems/merge-intervals/description/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        vector<vector<int>> output;
        output.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            vector<int>& last = output.back();
            vector<int> temp = intervals[i];
            if(last[1] >= temp[0]) last[1] = max(last[1], temp[1]);
            else output.push_back(temp);
        }
        return output;
    }
};