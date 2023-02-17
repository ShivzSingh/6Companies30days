class Solution {
public:
    int f(int idx , string s , vector<int> &dp){
        if(idx >= s.size()){
            return 1;
        }
        int opt1 , opt2 = 0;
        opt1 = s[idx] - '0';
        if(idx < s.size() - 1){
            opt2 = opt1*10 + s[idx+1] - '0';
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int ans = 0;
        if(opt1 > 0){
            ans += f(idx+1 , s , dp);
        }
        if(opt1 > 0 && opt2 > 0 && opt2 <=26){
            ans += f(idx+2 , s , dp);
        }
        return dp[idx] = ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1 , -1);
        return f(0 , s , dp);
    }
};