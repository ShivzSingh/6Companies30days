class Solution {
public:
    void Swap(vector<int>& nums , int i , int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void Reverse(vector<int>& nums , int i , int j){
        while( i < j){
            Swap(nums , i++ , j--);
        }
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1){
            return;
        }
        int i = nums.size()-2;
        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        if(i >= 0){
            int j = nums.size()-1;
            while(nums[i] >= nums[j]){
                j--;
            }
            Swap(nums , i , j);
        }
        Reverse(nums , i+1 , nums.size()-1);
        
    }
};