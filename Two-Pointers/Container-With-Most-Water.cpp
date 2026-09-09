// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int global = 0;
        int l = 0, r = height.size() - 1;
        while(l<=r){
            int ab = r - l;
            int mini = min(height[l], height[r]);
            global = max(global, ab*mini);
            if(height[l] < height[r]) l++;
            else r--;
        }
        return global;
    }
};