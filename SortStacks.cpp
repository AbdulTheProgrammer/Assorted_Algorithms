#include <stack>
#include <stdio.h>
void sortStack(std::stack<int> &s1) {
    std::stack<int> temp;
    if(s1.empty())
        return;
    temp.push(s1.top());
    s1.pop();
    while(!s1.empty()) {
        int newStackElm = s1.top();
        s1.pop();
        //find right place to put stack element
        while(!temp.empty() && newStackElm < temp.top()) {
            s1.push(temp.top());
            temp.pop();
        }
        temp.push(newStackElm);
    }

    //update the provided stack in ascending order
    while(!temp.empty()) {
        s1.push(temp.top());
        temp.pop();
    }

}

int main () {
    std::stack<int> test;
    test.push(1);
    test.push(34);
    test.push(5);
    test.push(9);
    test.push(72);
    sortStack(test);
    while(!test.empty()) {
        printf("%d \n", test.top());
        test.pop();
    }
}
