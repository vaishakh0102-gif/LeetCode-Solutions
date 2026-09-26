class Solution {
private:
    void comb(int ind,int target,int sum,int k,vector<int>&ds,vector<vector<int>>&ans){
        if(ds.size()==k){
            if(sum==target){

                ans.push_back(ds);
                return;
            }
        }
        for(int i=ind;i<=9;i++){
            ds.push_back(i);
            comb(i+1,target,sum+i,k,ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        vector<vector<int>>ans;
        comb(1,n,0,k,ds,ans);
        return ans;
        
    }
};