class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        vector<int> v;
        for(int i = 0 ; i < n ; i++){
            product = nums[i]*product;
            v.push_back(product);
        }
        product = 1;
        for(int i = n-2 ; i >= 0 ; i--){
            v[i+1] = v[i]*product;
            product = product*nums[i+1];
        }
        v[0] = product;
        return v;
    }
};