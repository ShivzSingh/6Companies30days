class Solution {
public:
    double Pow(double x, int n){
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        double ans = 1.0;
        if(n < 0){
            n = -1*n;
        }
        for(int i =0  ; i< n ; i++){
            ans = ans*x;
        }
        return ans;
        
    }
    
    double myPow(double x, int n) {
        long long nn = n;
        if(nn < 0){
            nn = -1*nn;
        }
        if(nn == 0){
            return 1;
        }
        double ans = myPow(x , nn/2);
        if(nn % 2 == 1){
            ans = ans*ans*x;
        }
        else{
            ans = ans*ans;
        }
        if(n < 0){
            return double(1.0)/double(ans);
        }
        return ans;
    }
};