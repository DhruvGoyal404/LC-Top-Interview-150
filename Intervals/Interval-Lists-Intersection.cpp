// https://leetcode.com/problems/interval-list-intersections/description/
class Solution {
public:
    bool checkOverlap(int start1, int end1, int start2, int end2){
        return max(start1, start2) <= min(end1, end2);
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> output;
        int l = 0, r = 0;
        while(l<firstList.size() && r<secondList.size()){
            int x1 = firstList[l][0], y1 = firstList[l][1], x2 = secondList[r][0], y2 = secondList[r][1];
            if(checkOverlap(x1, y1, x2, y2)){
                int overLappedX = max(x1, x2);
                int overLappedY = min(y1, y2);
                output.push_back({overLappedX, overLappedY});
            } 
            if(y1 <= y2) l++;
            else r++;
        }
        return output;
    }
};