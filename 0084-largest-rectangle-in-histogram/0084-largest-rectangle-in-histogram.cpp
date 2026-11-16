class Solution {
     vector<int> findPSEE(const vector<int>& heights) {
        int n = heights.size();
        vector<int> psee(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxarea=0;
        stack<int>st;
        int i=0;
        int nse=-1;
        vector<int> psee = findPSEE(heights);
        while(i<n){
            if(st.empty())st.push(i);
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int ele=heights[st.top()];
                st.pop();
                nse=i;
                int psee=st.empty()? -1:st.top();
                maxarea=max(maxarea,ele*(nse-psee-1));
            }
          
            st.push(i);
            i++;
            
        }
        while(!st.empty()){
            int ele=heights[st.top()];
            st.pop();
            nse=n;
            int psee=st.empty()? -1:st.top();
            maxarea=max(maxarea,ele*(nse-psee-1));
        }
        return maxarea;
        
    }
};