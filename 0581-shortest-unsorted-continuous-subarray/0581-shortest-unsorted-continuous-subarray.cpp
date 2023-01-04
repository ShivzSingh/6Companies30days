class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int start= 0;
        int end = -1;
        int maxi = nums[0];
        for(int i = 1 ; i < n ; i++){
            if(maxi > nums[i]){
                end = i;
            }
            else{
                maxi = nums[i];
            }
        }
        int mini = nums[n-1];
        for(int j = n-2 ; j >= 0 ; j--){
            if(mini < nums[j]){
               start = j;
            }
            else{
                 mini = nums[j];
            }
           
        }
        int ans = end - start + 1;
        return ans;
    }
};