class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
       
        sort(arr.begin(),arr.end());
         int n=arr.size();
        int longest=1;
        int cnt=1;
        for(int i=0;i<n-1;i++){
            if (arr[i]+1==arr[i+1]){
                cnt++;
                longest=max(longest,cnt);
            }
            else if (arr[i]==arr[i+1])continue;
            else cnt=1;
        }
        return longest;
        
        
    }
};
