class Solution {
public:

    long long calTime(vector<int>& piles,int hourly){
        long long time=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            time+=(piles[i]+(long long)hourly-1)/hourly;

        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=(low+high)/2;
            long long totalTime=calTime(piles,mid);
            if(totalTime<=h)high=mid-1;
            else low=mid+1;
        }
        return low;
        
    }
};