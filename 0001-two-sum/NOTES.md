Approach : - 1
using brutre force
vector<int> twoSum(vector<int>& nums, int target) {
vector<int> ans;
for(int i = 0 ; i < nums.size()-1 ; i++){
for(int j = i + 1 ; j < nums.size() ; j++){
if(nums[i] + nums[j] == target){
ans.push_back(i);
ans.push_back(j);
}
}
}
return ans;
}
Approach :- 2
using hashmap
vector<int> twoSum(vector<int>& nums, int target) {
unordered_map<int,int> mp;
vector<int> ans;
mp[nums[0]] = 0;
for(int i = 1 ; i < nums.size() ; i++){
int temp = target - nums[i];
if(mp.find(temp) != mp.end()){
ans.push_back(mp[temp]);
ans.push_back(i);
}
else{
mp[nums[i]] = i;
}
}
return ans;
}
Approach :- 3
using two pointer