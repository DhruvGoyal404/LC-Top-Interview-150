// https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wordLen = words[0].size(), wordCount = words.size();
        unordered_map<string, int> need;
        for(string word: words) need[word]++;
        for(int offset = 0; offset < wordLen; offset++) {
            int left = offset, count = 0;
            unordered_map<string, int> have;
            for(int right = offset; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);
                if(need.find(word) == need.end()) {
                    have.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }
                have[word]++;
                count++;
                while(have[word] > need[word]) {
                    string leftWord = s.substr(left, wordLen);
                    have[leftWord]--;
                    left += wordLen;
                    count--;
                }
                if(count == wordCount) {
                    ans.push_back(left);
                    string leftWord = s.substr(left, wordLen);
                    have[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }
        return ans;
    }
};