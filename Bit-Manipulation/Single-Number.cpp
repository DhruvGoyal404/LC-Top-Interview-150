// https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xori = 0;
        for(int k: nums) xori^=k;
        return xori;
    }
};