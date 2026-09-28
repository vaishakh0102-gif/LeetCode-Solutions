class Solution {
private:
    long long mod=1e9+7;
    long long power(long long base,long long exp){
        if(exp==0)return 1;
        long long half=power(base,exp/2);
        int ans=(half*half)% mod;
        if(exp%2==1)return (base*ans)%mod;
        else return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long evenslot=(n+1)/2;
        long long oddslot=n/2;
        return (power(5,evenslot)*power(4,oddslot))%mod;
        
    }
};