class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string r ="";
        stack<char>st;
        for(int i=n-1; i>=0; i--){
            if(s[i]!=' '){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    while(!st.empty()){
                     r = r+st.top();
                     st.pop();
                    }
                    r = r + ' ';
                }

            }
        }
        if (!st.empty()) {
            while (!st.empty()) {
                r += st.top();
                st.pop();
            }
        }

        if (!r.empty() && r.back() == ' ') {
            r.pop_back();
        }
        return r;
    }
};
