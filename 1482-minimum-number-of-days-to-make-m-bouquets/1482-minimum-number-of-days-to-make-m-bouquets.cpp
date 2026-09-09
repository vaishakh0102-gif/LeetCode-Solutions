class Solution {
public:

bool calDays(vector<int>& bloomDay,int day, int m, int k){
    int cnt=0;
    int numBoq=0;
    int n=bloomDay.size();
    for(int  i=0;i<n;i++){
        if(bloomDay[i]<=day)cnt++;
        else {
            numBoq+=(cnt/k);
            cnt=0;
        }
    }
    numBoq+=(cnt/k);
    return numBoq>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(m*1LL*k*1LL >n )return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=(low+high)/2;
            int days=calDays(bloomDay,mid,m,k);
            if(days==true)high=mid-1;
            else low=mid+1;
            
        }
        return low;
        
    }
    
};