// https://leetcode.com/problems/reverse-bits/
class Solution {
public:
    int reverseBits(int n) {
        string reversed_binary = "";
        for(int i = 0; i < 32; i++) {
            if((n >> i) & 1) reversed_binary += '1';
            else reversed_binary += '0';
        }
        return stoi(reversed_binary, nullptr, 2);
    }
};