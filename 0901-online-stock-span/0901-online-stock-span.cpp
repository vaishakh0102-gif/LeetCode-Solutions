class StockSpanner {
    stack<int>st;
    vector<int>arr;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        int i=arr.size()-1;

        while(!st.empty() && arr[st.top()]<=arr[i])st.pop();
        int pgee=st.empty()? i+1:i-st.top();
        st.push(i);
        return pgee;
        
    }

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */