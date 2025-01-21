class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        stack<char> st;

        for (char ch : s) {
            if (ch == '(') {
                if (!st.empty()) {
                    result += ch;
                }
                st.push(ch); // Push '(' onto the stack
            } else {         // ch == ')'
                st.pop();    // Pop the stack for every ')'
                if (!st.empty()) {
                    result +=
                        ch; // Add to result only if the stack is not empty
                }
            }
        }

        return result;
    }
};

