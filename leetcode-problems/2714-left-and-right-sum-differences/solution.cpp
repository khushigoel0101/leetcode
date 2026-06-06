class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        int sum = 0;
        for(int i =0; i<n; i++){
           sum += nums[i];
        }

        int leftsum = 0;
        for(int i =0; i<n; i++){
            sum -= nums[i];

            int rsum = sum;
            answer[i] = abs(leftsum - rsum);

            leftsum += nums[i];
        }
        return answer;
    }
};
