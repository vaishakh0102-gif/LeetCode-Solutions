class Solution {
private:
    void comb(int ind,string &ds,vector<string>&ans,string &digits,vector<string>&pad){
        int n=digits.size();
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        string letter=pad[digits[ind]-'0'];
        for(char ch:letter){
            ds.push_back(ch);
            comb(ind + 1, ds, ans, digits, pad);
            ds.pop_back();

        }
    }


public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string>pad={""," ","abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        string ds="";
        vector<string>ans;
        comb(0,ds,ans,digits,pad);
        return ans;
        
    }
};