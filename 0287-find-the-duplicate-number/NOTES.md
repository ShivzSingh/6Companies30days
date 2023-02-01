Approach :- 1
using brute force
int findDuplicate(vector<int>& nums) {
int n =  nums.size();
int ans = 0;
sort(nums.begin() , nums.end());
for(int i = 0 ; i < n ; i++){
for(int j = i+1 ; j  <n ; j++){
if(nums[i] == nums[i+1]){
ans = nums[i];
}
}
}
return ans;
}
gives TLE
Approach :- 2
using map
int findDuplicate(vector<int>& nums) {
int n =  nums.size();
int duplicate = 0;
map<int,int> mp;
for(int i = 0 ; i < n ; i++){
mp[nums[i]]++;
}
for(auto it : mp){
if(it.second > 1){
duplicate  = it.first;
break;
}
}
return duplicate;
}
Approcah :- 3
using binary search