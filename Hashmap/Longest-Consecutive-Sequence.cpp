// https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maximum = 1;
        if(nums.size() == 0) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto it: s){
            if(s.find(it-1) == s.end()){
                int counter = 1;
                int curr_streak = it;
                while(s.find(curr_streak+1)!=s.end()){
                    counter = counter+1;
                    curr_streak = curr_streak+1;
                }
                maximum = max(maximum, counter);
            }
        }
        return maximum;
    }
};