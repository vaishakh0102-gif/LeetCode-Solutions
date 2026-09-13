class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n=nums.size();
        int tsum=0;
         int sum=0;
        for(int i=0;i<n;i++){
            tsum+=nums[i];
           
            while(nums[i]>0){
                int digit=nums[i]%10;
                sum+=digit;
                nums[i]/=10;
            }

        }
        return tsum-sum;
        
    }
};