// https://leetcode.com/problems/squares-of-a-sorted-array/description/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg, pos;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0) neg.push_back(pow(nums[i], 2));
            else pos.push_back(pow(nums[i], 2));
        }
        int l = neg.size() - 1, r = 0;
        vector<int> output;
        while(l>=0 && r<pos.size()){
            if(neg[l] < pos[r]) output.push_back(neg[l--]);
            else output.push_back(pos[r++]);
        }
        while(l>=0 && r==pos.size()) output.push_back(neg[l--]);
        while(r<pos.size() && l<0) output.push_back(pos[r++]);
        return output;
    }
};