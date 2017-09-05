#include <stdio.h>
#include <stack>
#include <vector>

template<typename T>
class SetOfStacks {
    private:
        std::vector< std::stack<T> > stackList;
        void leftShift(int stackNo);
        int getLastStackI();
        int capacity;
    public:
        T pop();
        T popAtIndex(int stackNo);
        int push(T val);
        T peek();
};
template<typename T>
inline int SetOfStacks<T>::getLastStackI() {
    if(!stackList.size())
        return -1;
    return stackList.size() - 1;
}
template<typename T>
T SetOfStacks<T>::pop() {
    if(getLastStackI() != -1 )
        return NULL;
    T ret = stackList[getLastStackI()].top();
    stackList[getLastStackI()].pop();
    if(stackList[getLastStackI()].empty())
        stackList.pop_back();
    return ret;
}
template<typename T>
T SetOfStacks<T>::popAtIndex(int stackNo){
    if(getLastStackI() == -1)
        return NULL;
    if(stackNo > getLastStackI())
        return -1;
    T ret = stackList[getLastStackI()].top();
    if(stackNo < getLastStackI()){
        leftShift(stackNo);
        return ret;
    }
    stackList[stackNo].pop();
    return ret;
}
template<typename T>
int SetOfStacks<T>::push(T val) {
    if(stackList[getLastStackI()].size == capacity) {
        std::stack<T> s;
        stackList.push_back(s);
    }
    stackList[getLastStackI()].push(val);
    return 0;
}
template<typename T>
T SetOfStacks<T>::peek(){
    return stackList[getLastStackI()].top();
}
template<typename T>
void SetOfStacks<T>::leftShift(int stackNo){
    stackList[stackNo].pop();
    while(stackNo != getLastStackI() - 1) {
        // TODO: some of these functions do not exist
        // for stl stack, will have to create a custom stack class
        // to handle this or just simply use a vector instead
        T bottom = stackList[stackNo + 1].bottom();
        stackList[stackNo + 1].popBottom();
        stackList[stackNo].push(bottom);
        stackNo++;
    }
    if(!stackList[getLastStackI()].size()){
        stackList.pop_back();
    }
}
