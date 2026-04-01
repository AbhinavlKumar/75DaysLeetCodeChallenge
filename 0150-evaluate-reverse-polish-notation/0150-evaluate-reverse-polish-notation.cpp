class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        for (auto &t : tokens) {
            if (t.size() == 1 && (t[0] == '+' || t[0] == '-' || t[0] == '*' || t[0] == '/')) {
                int b = st.back(); st.pop_back();
                int a = st.back(); st.pop_back();
                if (t[0] == '+') st.push_back(a + b);
                else if (t[0] == '-') st.push_back(a - b);
                else if (t[0] == '*') st.push_back(a * b);
                else st.push_back(a / b);
            } else {
                int num = 0, sign = 1, i = 0;
                if (t[0] == '-') sign = -1, i = 1;
                for (; i < t.size(); i++) num = num * 10 + (t[i] - '0');
                st.push_back(sign * num);
            }
        }
        return st.back();
    }
};