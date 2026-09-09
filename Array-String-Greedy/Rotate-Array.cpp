// https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k%n == 0) return;
        k=k%n;
        reverse(nums.begin(), nums.begin()+(n-k));
        reverse(nums.begin()+(n-k), nums.begin()+n);
        reverse(nums.begin(), nums.begin()+n);

        // For left rotation:
        // reverse(a, a+d);
        // reverse(a+d, a+n);
        // reverse(a, a+n);
    }
};