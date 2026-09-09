// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Frequency Array Solution:
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<int, int> freq;
//         int left = 0, global_max = 0;
//         for(int i=0; i<s.length(); i++){
//             freq[s[i]]++;
//             while(freq[s[i]]>1){
//                 freq[s[left]]--;
//                 left++;
//             }
//             global_max = max(global_max, i - left + 1); 
//         }
//         return global_max;
//     }
// };
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char, int> lastSeen;
//         int left = 0, global_max = 0;
//         for(int i = 0; i < s.length(); i++) {
//             if(lastSeen.find(s[i]) != lastSeen.end()) left = max(left, lastSeen[s[i]] + 1);
//             lastSeen[s[i]] = i;
//             global_max = max(global_max, i - left + 1);
//         }
//         return global_max;
//     }
// };


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, global = 0;
        unordered_map<char, int> mpp;
        for(int i=0; i<s.length(); i++){
            while(mpp.find(s[i]) != mpp.end() && mpp[s[i]] >= 1){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) mpp.erase(s[l]);
                l++;
            }
            global = max(global, i - l + 1);
            mpp[s[i]]++;
        }
        return global;
    }
};