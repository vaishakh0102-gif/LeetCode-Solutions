class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long exp=n;
        if (exp<0){
            exp=-exp;
        }
        while(exp>0){
            if (exp%2==1){
                ans=ans*x;
                exp=exp-1;
            }
            else {
                x=x*x;
                exp=exp/2;
            }
        }
        if(n<0) return (double)1.0/ans;
        return ans;
    }
};