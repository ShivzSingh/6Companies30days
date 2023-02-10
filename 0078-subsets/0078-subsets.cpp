class Solution {
public:
    void f(int idx , vector<int>& nums , vector<int> &ds , vector<vector<int>> &ans){
        int n = nums.size();
        if(idx >= n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        f(idx+1 , nums , ds , ans);
        ds.pop_back();
        f(idx+1 , nums , ds , ans);
    }
    vector<vector<int>> subsets(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        f(0 , nums , ds , ans);
        return ans;
    } 
    
};