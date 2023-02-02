class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int tot_sum = 0;
        int window = 0;
        int left = 0;
        int right = n-k;
        for(int i = 0 ; i < n ; i++){
            tot_sum += cardPoints[i];
        }
        if(n == k){
            return tot_sum;
        }
        for(int i = 0 ; i < right ; i++){
            window += cardPoints[i];
        }
        int ans = tot_sum - window;
        while(right < n){
            window -= cardPoints[left++];
            window += cardPoints[right++];
            ans = max(ans , tot_sum - window);
        }
        return ans;
    }
};