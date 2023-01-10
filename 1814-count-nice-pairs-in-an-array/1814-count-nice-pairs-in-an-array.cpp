class Solution {
public:
    int rev(int n){
        int res = 0;
        while(n != 0){
            res = res*10 + n%10;
            n /= 10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        int res = 0;
        unordered_map<int ,int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            int temp = nums[i] - rev(nums[i]);
            mp[temp]++;
            res = (res + mp[temp] - 1) % 1000000007;
        }
        return res % 1000000007;
    }
};