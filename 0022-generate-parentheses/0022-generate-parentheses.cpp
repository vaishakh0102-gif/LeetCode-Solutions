class Solution {
private:
    void comb(int open,int  close,int n,string &ds,vector<string>&ans){
        if(open==n && close==n){
            ans.push_back(ds);
            return;
        }
        if(open<n){
            ds.push_back('(');
            comb(open+1,close,n,ds,ans);
            ds.pop_back();
        }
        if(close<open){
            ds.push_back(')');
            comb(open,close+1,n,ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string ds="";
        comb (0,0,n,ds,ans);
        return ans;
        
    }
};