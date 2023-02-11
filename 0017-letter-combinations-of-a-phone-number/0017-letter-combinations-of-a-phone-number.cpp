class Solution {
public:
    void f(int idx , string digits , string &temp , vector<string> &ans , unordered_map<char , string> &mp){
        if(idx == digits.size()){
            ans.push_back(temp);
            return ;
        }
        string str = mp[digits[idx]];
        for(int i = 0 ; i < str.size() ; i++){
            temp.push_back(str[i]);
            f(idx+1 , digits , temp , ans , mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp = "";
        if(digits=="") return ans;
        unordered_map<char , string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        f(0 , digits , temp , ans , mp);
        return ans;
    }
};