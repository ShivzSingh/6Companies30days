class Solution {
public:
    bool f(int idx , vector<int> &nums , vector<int> &dp){
        if(idx >= nums.size() - 1){
            return true;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        bool res = false;
        for(int i = 1 ; i <= nums[idx] ; idx++){
            res = res ||  f(idx+i , nums , dp);
        }
        return dp[idx] = res;
    }
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        int reach = 0;
        for(int i = 0 ; i <= reach ; i++){
            reach = max(reach , i + nums[i]);
                if(reach >= n-1){
                    return true;
                }
            
        }
        return false;
    }
};