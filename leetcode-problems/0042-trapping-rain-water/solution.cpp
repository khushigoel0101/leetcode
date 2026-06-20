class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int n = height.size(); 
        int tot = 0;
        for(int i = 0; i<n; i++){
            while(!st.empty() && height[i] >height[st.top()]){
                int top = st.top();
                st.pop();
                if(st.empty()) break;

                int left = st.top();
                int width = i- left - 1;
                int curr = min(height[left], height[i])-height[top];

                tot += width* curr;
            }
            st.push(i);
        }
        return tot;
    }
};
