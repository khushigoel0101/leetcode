class Solution {
public:
    void merge(vector<int>&nums, vector<int>& temp, int left, int right){
        //base case - only one el left just return
      if(left>=right){
        return;
      }
      //to prevent integer overflow
      int mid = left + (right - left) / 2;
      //sort on both 
      merge(nums,temp,left,mid);
      merge(nums,temp, mid+1, right);
      //merge two halves 
      int i = left;
      int j = mid+1;
      int k = left;

      while(i<=mid && j<=right){
        if(nums[i]<=nums[j]){
            temp[k++] = nums[i++];
        }else{
            temp[k++] = nums[j++];
        }
      }

      //copy remaining elements
      while(i<=mid){
        temp[k++] = nums[i++];
      }

      while(j<=right){
        temp[k++] = nums[j++];
      }
      //copy back the elements
      for(k = left; k<=right; k++){
        nums[k] = temp[k];
      }
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int>temp(nums.size());
        merge(nums,temp,0,nums.size()-1);
        return nums;
    }
};
