class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int tot = 0;
        while(start<end){
            leftMax = max(leftMax, height[start]);
            rightMax = max(rightMax, height[end]);

            if(leftMax < rightMax){
                tot += leftMax - height[start];
                start++;
            }else{
                tot += rightMax - height[end];
                end--;
            }

        }
        return tot ;
    }
};
