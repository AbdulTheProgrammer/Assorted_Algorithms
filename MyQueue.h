#include <stdio.h>
#include <stack>
template <typename T>
class MyQueue {
    private:
        std::stack<T> oldestStack;
        std::stack<T> newestStack;
    public:
        int enqueue(T val);
        T dequeue();
        T peek();
};
template <typename T>
int MyQueue<T>::enqueue(T val) {
    newestStack.push(val);
}
template <typename T>
T MyQueue<T>::dequeue() {
    if(oldestStack.empty() && newestStack.empty())
        return NULL;
    /* Gotcha optimization: Only tranfer from newest to oldest
     * when the oldest stack is empty, to keep ordering.
     */
    if(oldestStack.empty()) {
        while(!newestStack.empty()) {
            oldestStack.push(newestStack.top());
            newestStack.pop();
        }
    }
    T ret = oldestStack.top();
    oldestStack.pop();
    return ret;
}
template <typename T>
T MyQueue<T>::peek() {
    if(oldestStack.empty() && newestStack.empty())
        return NULL;
    if(oldestStack.empty()) {
        while(!newestStack.empty()) {
            oldestStack.push(newestStack.top());
            newestStack.pop();
        }
    }
    return oldestStack.top();
}
