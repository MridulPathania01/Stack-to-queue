#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> s; // stack to store elements
    stack<int> z; // temporary stack for popping

    void push(int x) {
        s.push(x);
    }

    int pop() {
        if (s.empty()) {
            cout << "Queue is empty. Cannot pop." << endl;
            return -1; // or throw an exception
        }
        while (!s.empty()) {
            z.push(s.top());
            s.pop();
        }
        int ans = z.top();
        z.pop();
        while (!z.empty()) {
            s.push(z.top());
            z.pop();
        }
        return ans;
    }

    int front() {
        if (s.empty()) {
            cout << "Queue is empty. Cannot get front." << endl;
            return -1; // or throw an exception
        }
        while (s.size() > 1) {
            z.push(s.top());
            s.pop();
        }
        int ans = s.top();
        while (!z.empty()) {
            s.push(z.top());
            z.pop();
        }
        return ans;
    }

    bool empty() {
        return s.empty();
    }
};
int main(){
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<< q.pop()<<endl;
    cout<<q.front()<<endl;
    cout<<q.empty()<<endl;
}