class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        //unordered_map<int,int> mp;
        vector<int> ans;
        //sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n ; i++){
            int idx = (abs(nums[i]) - 1);
            if(nums[idx] < 0){
                ans.push_back(idx+1);
            }
            else{
                nums[idx] = -1*nums[idx];
            }
        }
        return ans;
    }
};