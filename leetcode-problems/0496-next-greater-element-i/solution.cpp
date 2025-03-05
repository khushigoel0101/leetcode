class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int n1=nums1.size();
        int n2=nums2.size();
        for(int i=0;i<n1;i++)
        {
            int val=nums1[i];
            for(int j=0;j<n2;j++)
            {
                if(nums2[j]==val)
                {
                    for(int k=j+1;k<n2;k++)
                    {
                        if(nums2[k]>nums2[j])
                        {
                            arr.push_back(nums2[k]);
                            break;
                        }
                    }
                }
            }
            if(arr.size() < i+1)
            arr.push_back(-1);
        } 
        return arr;
    
    }
};
