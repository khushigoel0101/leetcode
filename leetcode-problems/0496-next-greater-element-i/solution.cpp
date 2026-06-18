class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nge(nums2.size());
        stack<int>st;
        vector<int>res;
        for(int i = nums2.size()-1 ; i>=0; i--){
           while(st.empty()!= true && st.top()<nums2[i]){
            st.pop();
           }
           if(!st.empty()){
            nge[i] = st.top();
           }else{
            nge[i] = -1;
           }
           st.push(nums2[i]);
        }
        for(int i = 0; i<nums1.size(); i++){
            auto it = std::find(nums2.begin(), nums2.end(), nums1[i]);
            int index = std::distance(nums2.begin(), it);
            res.push_back(nge[index]);
        }
        return res;
    }
};
