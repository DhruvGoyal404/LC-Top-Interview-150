// https://leetcode.com/problems/powx-n/
class Solution {
public:
    double fastPower(double x, long long N){
        if(N==0) return 1.0;
        double half = fastPower(x, N/2);
        if(N%2 == 0) return half*half; // this is the case for even exponential
        else return half*half*x; // this is for odd
    }
    
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0){
            x = 1.0/x;
            N = -N;
        } // pow(1/x, -N)
        return fastPower(x, N);
    }
};