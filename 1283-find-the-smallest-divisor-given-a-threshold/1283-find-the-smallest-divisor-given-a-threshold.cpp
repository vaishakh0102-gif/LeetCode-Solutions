class Solution {
public:

    bool possible(vector<int>& nums,int divisor,int threshold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/(double)divisor);

        }
        if (sum<=threshold)return true;
        return false;
        
    }




    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if (possible(nums,mid,threshold)==true)high=mid-1;
            else low=mid+1;

        }
        return low;
    }
   
        
    
   

};