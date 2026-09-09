// https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int a = nums[i], target = -a, l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int b = nums[l], c = nums[r];
                if (b + c == target) {
                    ans.push_back({a, b, c});
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
                else if (b + c < target) l++;
                else r--;
            }
        }
        return ans;
    }
};