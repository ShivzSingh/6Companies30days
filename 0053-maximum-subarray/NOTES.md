int maxSubArray(vector<int>& nums) {
int curr_sum = nums[0];
int best_sum = nums[0];
for(int i = 1 ;i < nums.size() ; i++){
if(curr_sum >= 0){
curr_sum += nums[i];
}
else{
curr_sum = nums[i];
}
if(curr_sum >best_sum){
best_sum = curr_sum;
}
}
return best_sum;
}