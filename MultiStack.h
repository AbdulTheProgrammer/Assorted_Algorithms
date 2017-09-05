template <typename T>
class MultiStack {
    private:
        T* sArray;
        int* stackp;
        int max_capacity;
        int stacks;
        int getSize(int stackNo);
    public:
        MultiStack(int capacity,int stacks);
        ~MultiStack();
        int push(T val, int stackNo);
        T pop(int stackNo);
};
template <typename T>
MultiStack<T>::MultiStack(int capacity,int numStacks) {
    stacks = numStacks;
    stackp = new int[stacks];
    for(int i = 0; i < stacks;i++)
        stackp = i*stacks;
    sArray = new T[capacity*stacks];
    max_capacity = capacity;
}
template <typename T>
MultiStack<T>::~MultiStack(){
    delete [] stackp;
    delete [] sArray;
}

template <typename T>
int MultiStack<T>::getSize(int stackNo) {
    if(stackNo > stacks || stackNo < 0)
        return -1;
    return stackp[stackNo] - stackNo*max_capacity;
}
template <typename T>
int MultiStack<T>::push(T val, int stackNo){
    int size = getSize(stackNo);
    if(size != -1 && size < max_capacity){
        sArray[stackp[stackNo]++] = val;
        return 0;
    }
    return -1;
}
template <typename T>
T MultiStack<T>::pop(int stackNo) {
    if(stackNo > stacks || stackNo < 0 || !getSize(stackNo))
        return -1;
    return sArray[stackp[stackNo]--];
}