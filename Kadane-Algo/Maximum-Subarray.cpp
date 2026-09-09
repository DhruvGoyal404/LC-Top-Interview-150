// https://leetcode.com/problems/maximum-subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0], best = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(curr < 0) curr = 0;
            curr += nums[i];
            best = max(best, curr);
        }
        return best;
    }
};