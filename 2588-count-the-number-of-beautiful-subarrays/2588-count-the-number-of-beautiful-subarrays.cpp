class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long cnt=0;
        long long xr=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<n;i++){
            xr=xr^nums[i];
            if(mpp.find(xr)!=mpp.end()){
                cnt+=mpp[xr];
            }
            mpp[xr]++;


        }
        return cnt;
        
    }
};