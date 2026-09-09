// https://leetcode.com/problems/factorial-trailing-zeroes/
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0, k = 5;
        while(k<=n){
            count+=n/k; k*=5;
        }
        return count;
    }
};