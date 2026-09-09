// https://leetcode.com/problems/maximum-sum-circular-subarray/
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

    int minSubArray(vector<int> &nums){
        int curr = nums[0], best = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(curr > 0) curr = 0;
            curr+=nums[i];
            best = min(best, curr);
        }
        return best;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        long long maxSum = maxSubArray(nums);
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long minSum = minSubArray(nums);
        long long circularMax = totalSum - minSum;
        if(maxSum < 0) return maxSum;
        return (int)max(maxSum, circularMax);
    }
};