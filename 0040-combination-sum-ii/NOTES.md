void f(int idx , vector<int>& candidates, int target , vector<vector<int>> &ans , vector<int> &ds){
if(target == 0){
ans.push_back(ds);
return;
}
for(int i = idx ; i < candidates.size() ; i++){
if(i > idx && candidates[i] == candidates[i-1]){
continue;
}
if(candidates[i] > target){
break;
}
ds.push_back(candidates[i]);
f(i+1 , candidates , target-candidates[i] , ans , ds);
ds.pop_back();
}
//f(idx+1 , candidates , target , ans , ds);
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
sort(candidates.begin(), candidates.end());
vector<vector<int>> ans;
vector<int> ds;
f(0 , candidates , target , ans , ds);
return ans;
}