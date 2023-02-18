class Solution {
public:
    int f(int idx , vector<int>& nums){
        if(idx == 0){
            return nums[0];
        }
        if(idx < 0){
            return 0;
        }
        int take = nums[idx] + f(idx-2 , nums);
        int notTake = f(idx-1 , nums);
        return max(take , notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 0);
        dp[0] = nums[0];
        for(int idx = 1 ; idx < n ; idx++){
            int take = nums[idx];
            if(idx > 1){
                take += dp[idx-2];
            }
            int notTake = dp[idx-1];
            dp[idx] = max(take , notTake);
        }
        return dp[n-1];
        
    }
};