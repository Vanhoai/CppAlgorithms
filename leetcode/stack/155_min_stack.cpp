#include <iostream>
using namespace std;

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        data.push(val);
        if (minStack.empty() || val <= minStack.top())
            minStack.push(val);
    }

    void pop() {
        if (data.top() == minStack.top())
            minStack.pop();

        data.pop();
    }

    int top() { return data.top(); }

    int getMin() { return minStack.top(); }

private:
    stack<int> data;
    stack<int> minStack;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;   // return -3
    minStack.pop();
    cout << minStack.top() << endl;      // return 0
    cout << minStack.getMin() << endl;   // return -2

    return 0;
}
