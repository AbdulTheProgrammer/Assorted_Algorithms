#include <stdio.h>
template<typename T>
class MinStack{
    private:
        struct StackN {
            StackN* next;
            T val;
            T min;
        };
        StackN* last;
    public:
        MinStack();
        int push(T val);
        T pop();
        T min();
        T peek();
};
template<typename T>
MinStack<T>::MinStack() {
    last = NULL;
}
template<typename T>
int MinStack<T>::push(T val){
    if(last == NULL){
        last = new StackN();
        last->next = NULL;
        last->val = val;
        last->min = val;
        return 0;
    }
    StackN* new_n = new StackN();
    new_n->val = val;
    new_n->next = last;
    new_n->min = val < last->min ? val: last->min;
    last = new_n;
    return 0;
}
template<typename T>
T MinStack<T>::pop(){
    if(last == NULL){
        return NULL;
    }
    StackN* temp = last;
    last = last->next;
    T return_val = temp->val;
    delete temp;
    temp = NULL;
    return return_val;
}
template<typename T>
T MinStack<T>::min(){
    if(last == NULL){
        return NULL;
    }
    return last->min;
}
template<typename T>
T MinStack<T>::peek(){
    if(last == NULL){
        return NULL;
    }
    return last->val;
}

#include <stack>
#include <stdio.h>
template<typename T>
class MinStack2{
    private:
        struct StackN {
            StackN* next;
            T val;
        };
        std::stack<T> minS;
        StackN* last;
    public:
        MinStack2();
        int push(T val);
        T pop();
        T min();
        T peek();
};
template<typename T>
MinStack2<T>::MinStack2() {
    last = NULL;
}
template<typename T>
int MinStack2<T>::push(T val){
    if(min() == NULL || min() > val) {
        minS.push(val);
    }
    StackN* new_node = new StackN();
    new_node->val = val;
    if(last == NULL) {
        last = new_node;
        return 0;
    }
    new_node->next = last;
    last = new_node;
}
template<typename T>
T MinStack2<T>::pop(){
    if(last == NULL){
        return NULL;
    }
    if(last->val == min())
        minS.pop();

    StackN* temp = last;
    last = last->next;
    T return_val = temp->val;
    delete temp;
    temp = NULL;
    return return_val;
}
template<typename T>
T MinStack2<T>::min(){
    if(minS.empty())
        return NULL;
    return minS.peek();
}
template<typename T>
T MinStack2<T>::peek(){
}