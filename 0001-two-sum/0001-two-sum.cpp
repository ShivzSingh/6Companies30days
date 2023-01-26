class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> pr;
        for(int i = 0 ; i < nums.size() ; i++){
            pr.push_back({nums[i] , i});
        }
        sort(pr.begin() , pr.end());
        int i = 0;
        int j = nums.size()-1;
        int idx1 = 0 , idx2 = 0;
        while(i < j){
            if(pr[i].first + pr[j].first == target){
                idx1 = pr[i].second ;
                idx2 = pr[j].second ;
                break;
            }
            else if(pr[i].first + pr[j].first > target){
                j--;
            }
            else if(pr[i].first + pr[j].first < target){
                i++;
            }
        }
        return {idx1 , idx2};
    }
};