class Solution {
public:
    vector<vector<int>> ans;
    void f(int idx , vector<int> &nums , vector<int> &ds , int target , int k){
        if(idx >= nums.size()){
            if(k == 0 && target == 0){
                ans.push_back(ds);
            }
            return;
        }
        if(nums[idx] <= target){
            ds.push_back(nums[idx]);
            f(idx+1 , nums , ds , target - nums[idx] , k-1);
            ds.pop_back();
        }
        f(idx+1 , nums, ds , target , k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        vector<int> ds;
        for(int i = 1 ; i <= 9 ; i++){
            nums.push_back(i);
        }
        f(0 , nums , ds , n , k);
        return ans;
    }
};