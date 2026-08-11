class StockSpanner {
public:
    stack<pair<int, int>>st;
    int idx;
    StockSpanner() {
        idx = 0;
        st.push({INT_MAX, -1});
    }
    int next(int price) {
        int ans;
        if(st.empty())
        {
            st.push({price, idx++});
            return 1;
        }
        else{
            while(!st.empty() && st.top().first <= price){
                st.pop();
            }
            if(st.empty()) return 1;
            ans = idx - st.top().second;
            st.push({price, idx++});
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */