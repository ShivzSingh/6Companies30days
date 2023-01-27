class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        int leftSum = 0;
        int rightSum = 0;
        int result = -1;
        for(int i = 0 ; i < n ; i++){
            totSum += nums[i];
        }
        for(int i = 0 ; i < n ; i++){
            rightSum = totSum - leftSum - nums[i];
            if(leftSum == rightSum){
                result = i;
                break;
            }
            leftSum += nums[i];
        }
        return result;
    }
};