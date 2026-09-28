class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9+7;

        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        
        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            left[i] = st.empty()? i+1 : i-st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            right[i] = st.empty() ? n-i : st.top() - i;
            st.push(i);
        }
        long long tot = 0;
        for(int i = 0; i<n; i++){
            long long cnt = (1LL*left[i]*right[i])%MOD;
            cnt = (cnt * arr[i])%MOD;
            tot = (tot+cnt)%MOD;
        }
        return tot;
    }
};
