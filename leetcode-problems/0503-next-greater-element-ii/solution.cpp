class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>ans(nums.size());
        for(int i = (nums.size()-1)*2; i>=0; i--){
             int index = i%nums.size();
             int curr = nums[index];
             while(!st.empty() && st.top() <= curr){
                st.pop();
            }
            if(i < nums.size()){
                if(st.empty())
                 ans[i] = -1;
                else
                 ans[i] = st.top();
            }
            st.push(curr);
        }
        return ans;
    }
};
