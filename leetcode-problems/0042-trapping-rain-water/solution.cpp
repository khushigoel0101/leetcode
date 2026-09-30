class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int lmax = 0, rmax = 0 , tot = 0;
        while(start<end){
            lmax = max(lmax, height[start]);
            rmax = max(rmax, height[end]);
            if(lmax<rmax){// bcz we don't care what's on the right water depends on shorter one
                tot += lmax - height[start];
                start++;
            }else{
                tot += rmax - height[end];
                end --;
            }
        }
        return tot;
    }
};
