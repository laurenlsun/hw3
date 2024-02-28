#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    Stack<int> s1;
    cout << "size: " << s1.size() << endl;
    if (s1.empty())
        cout << "is empty" << endl;
    s1.push(3);
    cout << "size: " << s1.size() << endl;
    s1.push(4);
    cout << "top: " << s1.top() << endl;
    cout << "size: " << s1.size() << endl;
    s1.pop();
    if (s1.empty())
        cout << "is empty" << endl;
    cout << "top: " << s1.top() << endl;
    cout << "size: " << s1.size() << endl;
    s1.pop();
    cout << "top: " << s1.top() << endl;
}