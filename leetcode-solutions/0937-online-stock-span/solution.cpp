class StockSpanner {
public:
    // Stack to store pairs of {price, index} where 'price' is the stock price 
    // and 'index' is its corresponding day (or index in the sequence).
    stack<pair<int,int>> st;

    // Keeps track of the current index of the stock prices.
    int currIdx = -1;

    // Constructor
    StockSpanner() {
        // Initialize the stack to ensure it's empty when the object is created or reset.
        while(!st.empty()) st.pop(); // Clear the stack to start fresh.
    }
    
    // This method takes the current day's stock price as input and returns 
    // the stock span, which is the number of consecutive days (including today) 
    // the stock price has been less than or equal to today's price.
    int next(int price) {
        // Increment the current index to reflect the next day's stock price.
        currIdx = currIdx + 1;

        // Pop elements from the stack as long as the price at the top of the stack
        // is less than or equal to the current price. These prices are irrelevant 
        // for calculating the span because today's price is greater than or equal to them.
        while(!st.empty() && st.top().first <= price) 
            st.pop();

        // If the stack is empty, it means there is no previous day with a higher price,
        // so the span is (currIdx - (-1)), which is currIdx + 1.
        // If the stack is not empty, the span is the difference between the current index
        // and the index of the most recent day with a higher price.
        int ans = currIdx - (st.empty() ? -1 : st.top().second); 

        // Push the current price and its index onto the stack for future calculations.
        st.push({price, currIdx});

        // Return the calculated span for the current day.
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

