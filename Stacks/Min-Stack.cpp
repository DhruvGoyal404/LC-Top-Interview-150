// https://leetcode.com/problems/min-stack/
class MinStack {
public:
    stack<int> st;
    stack<int> st2;
    MinStack() {}
    
    void push(int value) {
        st.push(value);
        if(st2.empty() || st2.top() > value) st2.push(value);
        else{
            int k = st2.top();
            st2.push(k);
        }
    }
    
    void pop() {
        st.pop();
        st2.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st2.top();
    }
};