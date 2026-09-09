// https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it: tokens){
            if(it == "+"){
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                st.push(x+y);
            } else if(it == "-"){
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                st.push(y-x);
            } else if(it == "*"){
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                st.push(x*y);
            } else if(it == "/"){
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                st.push(y/x);
            } else {
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};