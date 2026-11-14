class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char c:num){
            while(!st.empty() && k>0 && st.top()>c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        
        while(res.size()!=0 && res.back()=='0')res.pop_back();
        reverse(res.begin(),res.end());
        if(res.size()==0)return "0";
        return res;
        
    }
};