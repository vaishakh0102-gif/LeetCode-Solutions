class Solution {
public:
    bool canJump(vector<int>& nums) {  
        int n=nums.size();
        int maxindex=0;
        for(int i=0;i<n;i++){
            if(maxindex<i)return false;
            maxindex=max(maxindex,i+nums[i]);
           
            if(maxindex>=n-1)return true;
          
            
        }
        return false;
        
        
    }
};