// https://leetcode.com/problems/remove-duplicates-from-sorted-array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int slow = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nums[slow]){
                slow++;
                nums[slow]=nums[i];
            }
        }
        return slow+1;
    }
};