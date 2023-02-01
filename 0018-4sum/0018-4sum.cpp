class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        set<vector<int>> s;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ;j++){
                int k = j+1;
                int l = n-1;
                while(k < l){
                    long long int sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target){
                        s.insert({nums[i] , nums[j] , nums[k] , nums[l]});
                        k++;
                        l--;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        k++;
                    }
                }
                
            }
        }
        vector<vector<int>> res;
        for(auto quadruplets : s){
            res.push_back(quadruplets);
        }
            
        return res;
        
    }
};