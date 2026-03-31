class MinStack {
public:
    vector<int> st, mn;

    MinStack() {}

    void push(int val) {
        st.push_back(val);
        if (mn.empty() || val <= mn.back()) mn.push_back(val);
    }

    void pop() {
        if (st.back() == mn.back()) mn.pop_back();
        st.pop_back();
    }

    int top() {
        return st.back();
    }

    int getMin() {
        return mn.back();
    }
};