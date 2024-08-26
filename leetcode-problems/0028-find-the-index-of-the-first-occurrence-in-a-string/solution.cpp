class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 1,c=0, i =0,z=0;
        int n = haystack.length();
        int m = needle.length();
        for(i =0; i<n;){
            if(haystack[i]==needle[0]){
             z = i;
                j = 1;c=1;
                i++;
                while(j<m && haystack[i]==needle[j]){
                    c++;
                    i++;
                    j++;
                }
                if(c==m){
                    return z;
                }
                i =z+1;
            }
            else {
                 i++;
                }
                
        }
            
        
         return -1;
    }
};

