**using recursion**
int f(int idx , int n){
if(idx <= 1){
return 1;
}
return f(idx-1 , n) + f(idx-2 , n);
}
int climbStairs(int n) {
return f(n , n);
}
**memoization**
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
vector<int> dp(n+1 , 0);
return f(n , dp);
}
***using tabulation***
int climbStairs(int n) {
vector<int> dp(n+1 , 0);
dp[0] = 1;
dp[1] = 1;
for(int i = 2 ; i <= n ; i++){
dp[i] = dp[i-1] + dp[i-2];
}
return dp[n];
}
***using space optimization***
int climbStairs(int n) {
//vector<int> dp(n+1 , 0);
int prev2 = 1;
int prev = 1;
for(int i = 2 ; i <= n ; i++){
int curr = prev2 + prev;
prev2 = prev;
prev = curr;
}
return prev;
}