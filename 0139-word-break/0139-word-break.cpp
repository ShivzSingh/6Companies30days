class Solution {
public:
    bool f(int idx , string s , set<string> &wordDict , vector<int> &dp){
        if(idx == s.size()){
            return 1;
        }
        string temp;
        if(dp[idx] != -1){
            return dp[idx];
        }
        for(int j = idx ; j < s.size();  j++){
            temp += s[j];
            if(wordDict.find(temp) != wordDict.end()){
                if(f(j+1 , s , wordDict , dp)){
                    return dp[idx] = 1;
                }
            }
        }
        return dp[idx] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size() +1 , -1);
        set<string> st;
        for(auto x : wordDict){
            st.insert(x);
        }
        return f(0 , s , st , dp);
    }
};