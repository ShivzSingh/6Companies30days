class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int mini = INT_MAX;
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            int start = i+1;
            int end = n-1;
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                int diff = abs(sum - target);
                if(diff < mini){
                    mini = diff;
                    ans = sum;
                }
                if(sum > target){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
        return ans;
        
    }
};