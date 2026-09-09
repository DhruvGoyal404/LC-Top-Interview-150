// https://leetcode.com/problems/add-binary/
class Solution {
public:
    string addBinary(string h, string j) {
        int k = h.length() > j.length() ? h.length() : j.length();
        int carry = 0;
        string result = "";
        int i = h.length() - 1;
        int l = j.length() - 1;
        while(k--){
            int z = 0;
            if(i >= 0) z += h[i--] - '0';
            if(l >= 0) z += j[l--] - '0';
            if(carry == 1){
                z+=carry;
                carry = 0;
            }
            if(z == 0 || z == 1) result += char('0' + z);
            else{
                result += char('0' + z%2);;
                carry = z/2;
            }
        }
        if(carry == 1) result += char('0' + carry);;
        reverse(result.begin(), result.end());
        return result;
    }
};