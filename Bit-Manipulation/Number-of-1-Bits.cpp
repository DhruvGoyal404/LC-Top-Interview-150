// https://leetcode.com/problems/number-of-1-bits/
class Solution {
public:
    int hammingWeight(int n) {
        int sum = 0;
        while(n!=0){
            if(n%2) sum++;
            n/=2;
        }
        return sum;
    }
};