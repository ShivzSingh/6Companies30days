class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0){
            return "0";
        }
        string ans;
        if((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0)){
            ans.push_back('-');
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        long long quotient = numerator/denominator;
        long long rem = numerator%denominator;
        ans = ans + to_string(quotient);
        if(rem == 0){
            return ans;
        }
        ans += ".";
        map<long , long> mp;
        while(rem != 0){
            if(mp.find(rem) != mp.end()){
                int pos = mp[rem];
                ans.insert(pos , "(");
                ans += ')';
                break;
            }
            else{
                mp[rem] = ans.length();
                rem = rem*10;
                quotient = rem/denominator;
                rem = rem%denominator;
                ans += to_string(quotient);
            }
        }
        return ans;
    }
};