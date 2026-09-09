// https://leetcode.com/problems/insert-interval/
class Solution {
public:
    bool checkOverlap(int start1, int end1, int start2, int end2){
        return max(start1, start2) <= min(end1, end2);
    }

    vector<int> newPoints(int start1, int end1, int start2, int end2){
        return {min(start1, start2), max(end1, end2)};
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i=0;
        for(i = 0; i < intervals.size(); ){
            if(intervals[i][1] < newInterval[0]){
                result.push_back(intervals[i]);
                i++;
            }
            else if(intervals[i][0] > newInterval[1]) break;
            else{
                newInterval = newPoints(intervals[i][0], intervals[i][1], newInterval[0], newInterval[1]);
                i++;
            }
        }
        result.push_back(newInterval);
        while(i < intervals.size()) result.push_back(intervals[i++]);
        return result;
    }
};