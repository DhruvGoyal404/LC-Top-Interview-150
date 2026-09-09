// https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        int k = 0;
        unordered_map<string, int> mp;
        mp["I"] = 1; mp["V"] = 5; mp["X"] = 10;  mp["L"] = 50; mp["C"] = 100; mp["D"] = 500;  mp["M"] = 1000; mp["IV"] = 4; mp["IX"] = 9;  mp["XL"] = 40; mp["XC"] = 90; mp["CD"] = 400; mp["CM"] = 900;
        for(int i=0; i<s.length(); ){
            string check = "";
            check+=s[i];
            if(i+1 < s.length()) check+=s[i+1];
            if(mp.find(check) == mp.end()){
                string l = "";
                l += s[i];
                k+=mp[l];
                i++;
            } else {
                k+=mp[check];
                i+=2;
            }
        }
        return k;
    }
};