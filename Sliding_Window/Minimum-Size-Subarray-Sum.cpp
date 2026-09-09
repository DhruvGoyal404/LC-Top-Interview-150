// https://leetcode.com/problems/minimum-size-subarray-sum/description
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, global = INT_MAX, sum = 0, n = nums.size();
        while(r<n){
            sum += nums[r];
            while(sum>=target){
                global = min(global, r - l + 1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return global == INT_MAX?0:global;
    }
};