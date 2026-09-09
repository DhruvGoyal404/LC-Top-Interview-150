// https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<int> helper(string s){
        vector<int> temp(26, 0);
        for(char ch: s){
            if(ch>=65 && ch<=90) ch = ch + 32;
            temp[ch-'a']++;
        }
        return temp;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mpp;
        for(int i=0; i<strs.size(); i++){
            string s = strs[i];
            mpp[helper(s)].push_back(s);
        }
        vector<vector<string>> result;
        for(auto it: mpp)
            result.push_back(it.second);

        return result;
    }
};