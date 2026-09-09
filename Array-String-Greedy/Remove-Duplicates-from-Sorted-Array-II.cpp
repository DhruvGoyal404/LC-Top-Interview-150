// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int right = 0, count = 0, n = nums.size();
        while(right < n){
            if(count < 2) nums[count++] = nums[right];
            else if(nums[right] != nums[count - 2]) nums[count++] = nums[right];
            right++;
        }
        return count;
    }
};