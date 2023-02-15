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