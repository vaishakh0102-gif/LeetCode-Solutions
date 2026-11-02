class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==divisor)return 1;
        bool sign=true;
        if(dividend>0 && divisor<0)sign=false;
        if(dividend<0 && divisor>0)sign=false;
        long long  ans=0;
        long long n=abs((long long)dividend);
        long long d = abs((long long)divisor);

        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            ans+=(1LL<<cnt);
            n=n-(d<<cnt);

        }
        if (ans == (1LL << 31) && sign==true) return INT_MAX;
        if (ans == (1LL << 31) && sign==false) return INT_MIN;
        return sign?ans:-ans;
        
    }
};