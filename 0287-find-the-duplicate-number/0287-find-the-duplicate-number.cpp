class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n =  nums.size();
        int duplicate = 0;
        map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            if(it.second > 1){
                duplicate  = it.first;
                break;
            }
        }
        return duplicate;
    }
	
};

