#include <iostream>
using namespace std;

template<typename T>
class MyStack {
    T* data;
    int maxSize;
    int topIndex;
public:
    MyStack(int n) {
        maxSize = n;
        data = new T[maxSize];
        topIndex = -1;
    }

    ~MyStack() {
        delete[] data;
    }

    void push(T val) {
        if (is_full()) {
            cout << "Cannot push, stack is full!\n";
            return;
        }
        data[++topIndex] = val;
    }

    void pop() {
        if (is_empty()) {
            cout << "Cannot pop, stack is empty!\n";
            return;
        }
        topIndex--;
    }

    T top() {
        if (is_empty()) {
            cout << "No elements in stack.\n";
            return T();
        }
        return data[topIndex];
    }

    bool is_empty() {
        return topIndex < 0;
    }

    bool is_full() {
        return topIndex == maxSize - 1;
    }
};

int main() {
    MyStack<int> st(5);
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Current top: " << st.top() << endl;
    st.pop();
    cout << "Top after one pop: " << st.top() << endl;

    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);

    while (!st.is_empty()) {
        cout << "Removing: " << st.top() << endl;
        st.pop();
    }

    st.pop();

    return 0;
}
