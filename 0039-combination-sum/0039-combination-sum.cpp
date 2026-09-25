class Solution {

private:
    void printF(int ind,int target,vector<int>& candidates,int sum,vector<int>&ds,vector<vector<int>>&ans){
        int n=candidates.size();
        if(sum==target){
            ans.push_back(ds);
            return;
        }
        if (sum>target || ind==n)
            return;
        
        ds.push_back(candidates[ind]);
       
        printF(ind,target,candidates, sum+candidates[ind],ds,ans);
        ds.pop_back();
        printF(ind+1,target,candidates,sum,ds,ans);
    }
   

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int>ds;
        vector<vector<int>>ans;
        printF(0,target,candidates,0,ds,ans);
        return ans;


        
    }
};