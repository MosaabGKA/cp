// this is just to get min and max in the queue
struct myQ {
    stack<int> left, leftmn, leftmx;
    stack<int> right, rightmn, rightmx;
    void trans() {
        left.push(right.top());
        leftmn.push(right.top());
        leftmx.push(right.top());
        right.pop();
        rightmn.pop();
        rightmx.pop();
        while (!right.empty()) {
            left.push(right.top());
            leftmn.push(min(right.top(),leftmn.top()));
            leftmx.push(max(right.top(),leftmx.top()));
            right.pop();
            rightmn.pop();
            rightmx.pop();
        }
    }
    void rem() {
        if(left.empty())
            trans();
        left.pop();
        leftmn.pop();
        leftmx.pop();
    }
    void add(int x) {
        int rmn = right.empty() ? INT_MAX : rightmn.top();
        int rmx = right.empty() ? INT_MIN : rightmx.top();
        right.push(x);
        rightmn.push(min(rmn,x));
        rightmx.push(max(rmx,x));
    }
    int mn() {
        int rmn = right.empty() ? INT_MAX : rightmn.top();
        int lmn = left.empty() ? INT_MAX : leftmn.top();
        return min(rmn,lmn);
    }
    int mx() {
        int rmx = right.empty() ? INT_MIN : rightmx.top();
        int lmx = left.empty() ? INT_MIN : leftmx.top();
        return max(rmx,lmx);
    }
};
