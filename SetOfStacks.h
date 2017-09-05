#include <stdio.h>
#include <stack>
#include <vector>

template<typename T>
class SetOfStacks {
    private:
        std::vector< std::stack<T> > stackList;
        int stacks;
        void leftShift(int stackNo);
        int capacity;
    public:
        T pop();
        T popAtIndex(int stackNo);
        int push(T val);
        T peek();
};

template<typename T>
T SetOfStacks<T>::pop() {
    if(stackList[stacks].empty())
        return NULL;
    T ret = stackList[stacks].top();
    stackList[stacks].pop();
    if(stackList[stacks].empty())
        stacks--;
    return ret;
}
template<typename T>
T SetOfStacks<T>::popAtIndex(int stackNo){
    if(stackNo > stacks)
        return -1;
    T ret = stackList[stacks].top();
    if(stackNo < stacks){
        leftShift(stackNo);
        return ret;
    }
    stackList[stackNo].pop();
    return ret;
}
template<typename T>
int SetOfStacks<T>::push(T val) {
    if(stackList[stacks].size == capacity) {
        std::stack<T> s;
        stackList[++stacks] = s;
    }
    stackList[stacks].push(val);
    return 0;
}
template<typename T>
T SetOfStacks<T>::peek(){
    return stackList[stacks].top();
}
template<typename T>
void SetOfStacks<T>::leftShift(int stackNo){
    while(stackNo != stacks - 1) {
        // TODO: some of these functions do not exist will
        // for stl stack, will have to create a custom stack class
        // to handle this
        stackList[stackNo].pop();
        T bottom = stackList[stackNo + 1].bottom();
        stackList[stackNo + 1].popBottom();
        stackList[stackNo].push(bottom);
        stackNo++;
    }
    if(!stackList[stacks].size()){
        stacks--;
    }
}
