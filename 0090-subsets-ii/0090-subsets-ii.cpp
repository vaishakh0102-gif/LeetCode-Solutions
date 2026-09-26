class Solution {
private:
    void comb(int ind,vector<int>& nums, vector<int>&ds, vector<vector<int>>&ans){
        int n =nums.size();
        ans.push_back(ds);
        for (int i=ind;i<n;i++){
            if (i>ind && nums[i]==nums[i-1])continue;
            
            ds.push_back(nums[i]);
            comb(i+1,nums,ds,ans);
            ds.pop_back();
        }
       

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        vector<vector<int>>ans;
        comb(0,nums,ds,ans);
        return ans;
        
    }
};