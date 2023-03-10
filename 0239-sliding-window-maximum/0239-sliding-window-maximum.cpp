class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if(n < k){
            ans.push_back(*max_element(nums.begin() , nums.end()));
            return ans;
        }
        deque<int> q;
        int i = 0 , j = 0;
        while(j < n){
            while(!q.empty() && q.back() < nums[j]){
                q.pop_back();
            }
            q.push_back(nums[j]);
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                ans.push_back(q.front());
                if(nums[i] == q.front()){
                    q.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};