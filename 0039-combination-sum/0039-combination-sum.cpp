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
            f(idx , candidates , target - candidates[idx] , ans , ds);
            ds.pop_back();
        }
        f(idx+1 , candidates , target , ans , ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(0 , candidates , target , ans , ds);
        return ans;
    }
};