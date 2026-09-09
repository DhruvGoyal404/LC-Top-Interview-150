// https://leetcode.com/problems/h-index/
class Solution {
public:
    bool valid(vector<int> &citations, int mid){
        int k = 0;
        for(int j: citations) if(j>=mid) k++;
        return k>=mid;
    }

    int hIndex(vector<int>& citations) {
        int l = 0, h = citations.size();
        while(l<=h){
            int mid = l + (h - l)/2;
            if(valid(citations, mid)) l = mid + 1;
            else h = mid - 1;
        }
        return h;
    }
};