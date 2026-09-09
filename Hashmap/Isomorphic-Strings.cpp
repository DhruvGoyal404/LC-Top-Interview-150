// https://leetcode.com/problems/isomorphic-strings/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, char> mp;
        unordered_map<char, char> mp2;
        int i=0, j=0;
        while(i<s.length()){
            if(mp.find(s[i]) != mp.end()) if(mp[s[i]] != t[i]) return false;
            if(mp2.find(t[i]) != mp2.end()) if(mp2[t[i]] != s[i]) return false;
            mp[s[i]] = t[i];
            mp2[t[i]] = s[i];
            i++;
        }
        for(auto it: mp){
            char fir = it.first, sec = it.second;
            if(mp2[sec]!=fir) return false;
        }
        return true;
    }
};