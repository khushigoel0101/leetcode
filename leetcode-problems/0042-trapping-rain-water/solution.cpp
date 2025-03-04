class Solution {
public:
    int trap(vector<int>& height) {
    stack<int> st; // Monotonic decreasing stack
    int n = height.size(), totalWater = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty()) break; // No left boundary

            int left = st.top();  // Left boundary index
            int width = i - left - 1;
            int waterHeight = min(height[left], height[i]) - height[top];

            totalWater += width * waterHeight; // Compute trapped water
        }
        st.push(i);
    }
    return totalWater;

    }
};
