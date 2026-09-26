#include <vector>
#include <stack>

class Solution {
public:
    int sumSubarrayMins(std::vector<int>& arr) {
        int n = arr.size();
        int MOD = 1e9 + 7;
        
        // Arrays to store the distance to the Previous Less Element (PLE) 
        // and Next Less Element (NLE)
        std::vector<int> left(n);
        std::vector<int> right(n);
        
        std::stack<int> st;
        
        // 1. Find Previous Less Element (PLE) - using strictly less (<)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            // If stack is empty, there is no smaller element to the left.
            // Distance is i - (-1) = i + 1.
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }
        
        // Clear stack for the next pass
        while (!st.empty()) st.pop();
        
        // 2. Find Next Less Element (NLE) - using less than or equal (<=) to prevent duplicates
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            // If stack is empty, there is no smaller/equal element to the right.
            // Distance is n - i.
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }
        
        // 3. Calculate total contribution
        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            long long subarrays = (1LL * left[i] * right[i]) % MOD;
            subarrays = (subarrays * arr[i]) % MOD;
            totalSum = (totalSum + subarrays) % MOD;
        }
        
        return totalSum;
    }
};
