class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2){
            return n;
        }
        int maxi = 2;
        for(int i = 0 ; i < n-1 ; i++){
            map<double , int> mp;
            for(int j = 0 ; j < n ; j++){
                if(i == j){
                    continue;
                }
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                double tangent = atan2((y2-y1),(x2-x1));
                mp[tangent]++;
                maxi = max(maxi , mp[tangent]+1);
            }
        }
        return maxi;
    }
};