// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto first = lower_bound(nums.begin(), nums.end(), target);

        if (first == nums.end() || *first != target)
            return {-1, -1};

        auto last = upper_bound(nums.begin(), nums.end(), target);

        return {
            static_cast<int>(first - nums.begin()),
            static_cast<int>(last - nums.begin()) - 1
        };
    }
};