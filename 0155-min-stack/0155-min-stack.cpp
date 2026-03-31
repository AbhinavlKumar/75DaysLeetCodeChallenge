class MinStack {
public:
    vector<int> st, mn;

    MinStack() {
        st.reserve(30000);
        mn.reserve(30000);
    }

    void push(int val) {
        st.emplace_back(val);
        if (mn.empty() || val <= mn.back()) mn.emplace_back(val);
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