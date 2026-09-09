// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    bool checkOverlap(pair<int, int> p1, pair<int, int> p2){
        return max(p1.first, p2.first) <= min(p1.second, p2.second);
    }

    pair<int, int> findOverlappedRegion(pair<int, int> p1, pair<int, int> p2){
        return {max(p1.first, p2.first), min(p1.second, p2.second)};
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int, int>> mp;
        for(int i=0; i<points.size(); i++) mp.push_back({points[i][0], points[i][1]});
        sort(mp.begin(), mp.end());
        int count = 0, i = 0, n = mp.size();
        while(i < n) {
            pair<int, int> curr = mp[i];
            while(i+1<n && checkOverlap(curr, mp[i+1])) {
                curr = findOverlappedRegion(curr, mp[i+1]);
                i++;
            }
            count++;
            i++;
        }
        return count;
    }
};