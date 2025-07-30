class MinStack {
public:
    stack<long long> st;
    long long minVal;

public:
    MinStack() {
        // Initialize your data structure here
        // minVal = INT_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            minVal = val;
            st.push(val);
        } else {
            if (val < minVal) {
                long long modifiedVal = 2LL * val - minVal;
                minVal = val;
                st.push(modifiedVal);
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        long long top = st.top();
        st.pop();
        if (top < minVal) {
            minVal = 2 * minVal - top;
        }
    }

    int top() {
        long long top;
        if (st.top() < minVal) {
            top = minVal;
        } else {
            top = st.top();
        }
        return (int)top;
    }

    int getMin() { return (int)minVal; }
};