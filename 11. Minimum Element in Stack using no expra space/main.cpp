// https://www.youtube.com/watch?v=ZvaRHYYI0-4&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=11


/*

Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.


*/

// https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/


#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<long long> s;
    long long minEle;

public:
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            minEle = x;
        } else {
            if (x >= minEle) {
                s.push(x);
            } else {
                s.push(2LL * x - minEle);
                minEle = x;
            }
        }
    }

    void pop() {
        if (s.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        long long top = s.top();
        s.pop();

        if (top < minEle) {
            // Encoded value: retrieve previous min
            minEle = 2 * minEle - top;
        }
    }

    int top() {
        if (s.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        long long top = s.top();
        if (top >= minEle) {
            return top;
        } else {
            // Encoded value
            return minEle;
        }
    }

    int getMin() {
        if (s.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minEle;
    }

    bool isEmpty() {
        return s.empty();
    }
};

int main() {
    SpecialStack st;
    st.push(5);
    st.push(2);
    st.push(1);
    st.push(3);

    cout << "Current Min: " << st.getMin() << "\n"; // 1
    st.pop();
    cout << "Current Min: " << st.getMin() << "\n"; // 1
    st.pop();
    cout << "Current Min: " << st.getMin() << "\n"; // 2
    st.pop();
    cout << "Current Min: " << st.getMin() << "\n"; // 5

    return 0;
}
