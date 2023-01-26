class Solution {
public:
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
};