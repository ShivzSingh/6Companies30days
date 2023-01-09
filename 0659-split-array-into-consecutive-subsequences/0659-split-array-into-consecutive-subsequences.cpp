class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> Availability;
        unordered_map<int,int> vacancy;
        for(int i = 0 ; i < n ; i++){
            Availability[nums[i]]++;
        }
        for(int i = 0 ; i < n ; i++){
            if(Availability[nums[i]] == 0){
                continue;
            }
            else if(vacancy[nums[i]] > 0){
                Availability[nums[i]]--;
                vacancy[nums[i]]--;
                vacancy[nums[i]+1]++;
            }
            else if(Availability[nums[i]] > 0 && Availability[nums[i]+1] > 0 && Availability[nums[i]+2] > 0){
                Availability[nums[i]]--;
                Availability[nums[i]+1]--;
                Availability[nums[i]+2]--;
                vacancy[nums[i]+3]++;
            }
            else{
                return false;;
            }
        }
        return true;
    }
};