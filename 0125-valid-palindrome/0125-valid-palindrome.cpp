class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin() , s.end() , s.begin() , ::tolower);
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] >= 97 && s[i] <= 122 || s[i] >= 48 && s[i] <= 57){
                continue;
            }
            else{
                s.erase(i , 1);
                i--;
            }
        }
        int l = 0;
        int r = s.size()-1;
        while(l <= r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};