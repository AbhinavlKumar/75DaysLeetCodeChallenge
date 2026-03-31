class MinStack {
    stack<int> st, mn;
public:
    void push(int val) {
        st.push(val);
        if (mn.empty() || val <= mn.top()) mn.push(val);
    }
    void pop() {
        if (st.top() == mn.top()) mn.pop();
        st.pop();
    }
    int top() const { return st.top(); }
    int getMin() const { return mn.top(); }
};