// https://leetcode.com/problems/summary-ranges/
class Solution {
public:
    vector<string> output;

    void helper(vector<int> &nums, int l, int r){
        if(l == r) output.push_back(to_string(nums[l]));
        else output.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
    }

    vector<string> summaryRanges(vector<int>& nums) {
        int l = 0;
        while(l<nums.size()){
            int r = l+1;
            while(r<nums.size() && (long long)nums[r] - nums[r-1] == 1) r++;
            helper(nums, l, r - 1);
            l = r;
        }
        return output;
    }
};