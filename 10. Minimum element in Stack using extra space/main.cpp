// https://www.youtube.com/watch?v=asf9P2Rcopo&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=10

/*

Design a Data Structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. All these operations of SpecialStack must be O(1). To implement SpecialStack, you should only use standard Stack data structure and no other data structure like arrays, list, .. etc.

*/

// https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/

// use s stack to do push and pop
// and a supportnig stack to find the minimum element of the stackk at aany time 

#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
    stack<int> s;
    stack<int> minStack;

public:
    bool isEmpty() {
        return s.empty();
    }

    bool isFull(int n) {
        return s.size() == n;
    }

    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        } else {
            minStack.push(minStack.top());
        }
    }

    int pop() { 
        if (s.empty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        minStack.pop();
        int val = s.top();
        s.pop();
        return val;
    }

    int getMin() {
        if (minStack.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minStack.top();
    }
};

int main() {
    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(5);
    s.push(8);

    cout << "Minimum: " << s.getMin() << endl; // 5
    s.pop(); // removes 8
    cout << "Minimum: " << s.getMin() << endl; // still 5
    s.pop(); // removes 5
    cout << "Minimum: " << s.getMin() << endl; // 10

    return 0;
}
