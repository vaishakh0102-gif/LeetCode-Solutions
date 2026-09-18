class Solution {
private:
    int lb(vector<int> arr,int n,int k){
        sort(arr.begin(), arr.end());
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=(low+high)/2;
            if (arr[mid]>=k){
                ans=mid;
                high=mid-1;

            }
            else low=mid+1;
        }
        return ans;
    }
    

public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        
        
        int ind=0;
        int cnt_max=0;
        int n=mat.size();
        int m=mat[0].size();
        for (int i=0;i<n;i++){
            int cnt_ones=m-lb(mat[i],m,1);
            if (cnt_ones>cnt_max){
                cnt_max=cnt_ones;
                ind =i;
            }
            

        }
        return {ind,cnt_max};
        
        
    }
};