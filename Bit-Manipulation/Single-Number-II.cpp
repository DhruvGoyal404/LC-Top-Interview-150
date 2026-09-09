// https://leetcode.com/problems/single-number-ii/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitCount(32, 0);
        for(int x: nums){
            for(int i = 0; i < 32; i++) if((x >> i) & 1) bitCount[i]++;
        }
        int ans = 0;
        for(int i = 0; i < 32; i++) if(bitCount[i] % 3) ans |= (1 << i);
        return ans;
    }
};