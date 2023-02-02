Approaach :- 1
using recursion
int f(int idx , vector<int>& nums){
if(idx >= nums.size()-1){
return 0;
}
int min_jumps =10001;
for(int j = 1 ; j <= nums[idx] ; j++){
if(idx + j <= nums.size() - 1){
min_jumps = min(min_jumps , 1 + f(idx + j , nums));
}
}
return min_jumps;
}
int jump(vector<int>& nums) {
int n = nums.size();
return f(0 , nums);
}
gives TLE
Approach :- 2
using mamoization