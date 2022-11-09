class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int, int>> st;
    int next(int price) {
         int count = 0;

        // find no. of elements less than or equal to curr price

        while(st.empty() == false && st.top().first <= price)
        {
            // update count

            count += st.top().second;

            // pop the smaller element

            st.pop();
        }

        // increment the count for curr price

        count++;

        // push the {price, count} into stack

        st.push({price, count});

        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */