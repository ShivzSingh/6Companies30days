class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        int n = points.size();
        for(int i = 0 ; i < n ; i++){
            map<int , int> mp;
            for(int j = 0 ; j < n ; j++){
                if(i == j){
                    continue;
                }
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                int dist = x*x;
                dist += y*y;
                mp[dist] ++;
            }
            for(auto &it : mp){
                if(it.second > 1){
                    res += (it.second)*(it.second-1);
                }
            }
        }
        return res;
    }
};