class Solution {
public:
    void f(int idx , vector<int>& candidates, int target , vector<vector<int>> &ans , vector<int> &ds){
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[idx] <= target){
            ds.push_back(candidates[idx]);
            f(idx+1 , candidates , target - candidates[idx] , ans , ds);
            ds.pop_back();
        }
        while(idx+1 < candidates.size() && candidates[idx] == candidates[idx+1]){
            if(candidates[idx] > target){
                break;
            }
            idx++;
        }
        f(idx+1 , candidates , target , ans , ds);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        f(0 , candidates , target , ans , ds);
        return ans;
    }
};