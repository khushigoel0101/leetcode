class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2= nums2.size();
        int i =0,j =0;
        int n = n1+ n2;
        int in2 = n/2;
        int in1 = in2 - 1;
        int c =0; int inel1 = -1; int inel2 = -1;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(c == in1) inel1 = nums1[i];
                if(c == in2) inel2 = nums1[i];
                c++; i++; 
            }
            else{
                if(c == in1) inel1 = nums2[j];
                if(c == in2) inel2 = nums2[j];
                c++; j++;
            }
        }
        while(i<n1){
            if(c == in1) inel1 = nums1[i];
                if(c == in2) inel2 = nums1[i];
                c++; i++;
        }
        while(j<n2){
            if(c == in1) inel1 = nums2[j];
                if(c == in2) inel2 = nums2[j];
                c++; j++;
        }
        if(n%2 == 1){
            return inel2;
        }
        else{
            return (double)((double)inel1 + inel2)/2.0;
        }
    }
};
