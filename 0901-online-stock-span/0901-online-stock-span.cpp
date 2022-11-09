class StockSpanner {
    int index;
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        int ans;
        while(!st.empty() && price >= st.top().second){
            st.pop();
        }
        
        if(st.empty()) ans = index+1;
        else ans = index-st.top().first;
        
        st.push({index,price});
        index++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */