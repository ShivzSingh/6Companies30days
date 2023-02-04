class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //step :- 1 mark element which are out of range and mark presence of one.
        bool one  = false;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 1){
                one = true;
            }
            if(nums[i] > n || nums[i] < 1){
                nums[i] = 1;
            }
        }
        if(one == false){
            return 1;
        }
        //step :- 2 Map elements with index
        for(int i = 0 ; i < n ; i++){
            int idx = abs(nums[i]);
            nums[idx-1] = -(abs(nums[idx-1]));
        }
        //step :- 3 Find out missing integer
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > 0){
                return i+1;
            }
        }
        return n+1;
    }
};