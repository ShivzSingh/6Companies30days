class Solution {
public:
    int f(int idx , vector<int> &dp){
        if(idx <= 1){
            return 1;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        return dp[idx] = f(idx-1 , dp) + f(idx-2 , dp);
    }
    int climbStairs(int n) {
        //vector<int> dp(n+1 , 0);
        int prev1 = 1;
        int prev2 = 1;
        for(int i = 2 ; i <= n ; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr; 
        }
        return prev1;
    }
};