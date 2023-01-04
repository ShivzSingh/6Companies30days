class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        map<pair<int,int>  ,int> mp;
        for(auto &it : rectangles){
            mp[{it[0] , it[1]}]++;
            mp[{it[2] , it[3]}]++;
            mp[{it[0] , it[3]}]--;
            mp[{it[2] , it[1]}]--;
        }
        int corners = 0;
        for(auto &it : mp){
            if(it.second != 0){
                if(abs(it.second) != 1){
                    return false;
                }
                corners++;
            }
        }
        return corners == 4;
    }
};