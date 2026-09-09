// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0) return nums[0];
        if(n == 1) return (k % 2 ? -1 : nums[0]);
        if(k == 1) return nums[1];
        if(k == n) return *max_element(nums.begin(), nums.end() - 1);
        if(k > n) return *max_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.begin() + k - 1);
        return max(maxi, nums[k]);
    }
};