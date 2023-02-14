class Solution {
public:
    int f(int idx , vector<int>& coins, int amount , vector<vector<int>> &dp){
        if(idx == 0){
            if(amount % coins[idx] == 0){
                return amount/coins[idx];
            }
            else{
                return 1e9;
            }
        }
        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }
        int notTake = f(idx-1 , coins , amount , dp);
        int take = INT_MAX;
        if(coins[idx] <= amount){
            take = 1 + f(idx , coins , amount - coins[idx] , dp);
        }
        return dp[idx][amount] = min(notTake , take);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1 , 0);
        vector<int> curr(amount+1 , 0);
        for(int idx = 0 ; idx <= amount ; idx++){
            if(idx % coins[0] == 0){
                prev[idx] = idx/coins[0];
            }
            else{
                prev[idx] = 1e9;
            }
        }
        for(int idx = 1 ; idx < n ; idx++){
            for(int target = 0 ; target <= amount ; target++){
                int notTake = prev[target];
                int take = INT_MAX;
                    if(coins[idx] <= target){
                        take = 1 + curr[target-coins[idx]];
                }
                curr[target] = min(notTake , take);
                
            }
            prev = curr;
            
        }
        int res = prev[amount];
        if(res == 1e9){
            return -1;
        }
        else{
            return res;
        }
        
    }
};