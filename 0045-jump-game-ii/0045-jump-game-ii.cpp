class Solution {
public:
    int f(int idx , vector<int>& nums , vector<int> &dp){
        if(idx >= nums.size()-1){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int min_jumps =10001;
        for(int j = 1 ; j <= nums[idx] ; j++){
            if(idx + j <= nums.size() - 1){
                min_jumps = min(min_jumps , 1 + f(idx + j , nums , dp));
            }
        }
        return dp[idx] = min_jumps;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1 , 0);
        dp[n-1] = 0;
        for(int idx = n-2 ; idx >= 0 ; idx--){
            int min_jumps = 10001;
            for(int j = 1 ; j <= nums[idx] ; j++){
                if(idx + j <= nums.size() - 1){
                    min_jumps = min(min_jumps , 1 + dp[idx + j]);
                }
            }
            dp[idx] = min_jumps;
        }
        return dp[0];
    }
};