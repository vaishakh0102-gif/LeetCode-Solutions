class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n=nums.size();
        long long SN=(n*(n+1)/2);
        long long SN2=(n*(n+1)*(2*n+1)/6);
        long long S=0,S2=0;
        for(int i=0;i<n;i++){
            S+=nums[i];
            S2+=(long long)nums[i]*(long long )nums[i];
        }
        long long val1=S-SN;
        long long val2=S2-SN2;
        val2=val2/val1;
        long long x=(val1+val2)/2;
        long long y=val2-x;
        return {(int)x,(int)y};

        
        
    }
};