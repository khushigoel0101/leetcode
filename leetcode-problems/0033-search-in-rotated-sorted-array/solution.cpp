class Solution {
public:
    int find_pivot(vector<int>& nums, int low, int high){
        while(low<high){
            int mid = low + (high-low)/2;
            if(nums[mid]>nums[high]){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return high;
    }

    int binarysearch(vector<int>& nums, int low, int high, int target){
        int n = nums.size();
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]>target){
                high = mid -1;
            }else if(nums[mid]<target){
                low = mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = find_pivot(nums,0,n-1);
        if(nums[pivot]==target){
            return pivot;
        }

        int res = -1;
        res = binarysearch(nums,pivot+1,n-1,target);
        if(res!=-1) return res;

        res = binarysearch(nums,0,pivot-1, target);
        return res;
    }
};
