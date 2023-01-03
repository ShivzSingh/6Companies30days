class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int n = nums.size();
        int sum = 0;
        int fO = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            fO += i*nums[i];
        }
        int dp[n];
        dp[0] = fO;
        int maxi = fO;
        for(int i = 1 ; i < n ; i++){
            dp[i] = dp[i-1] + sum - n*(nums[n-i]);
            maxi = max(dp[i] , maxi);
        }
        return maxi;
    }
};