#include "heap.h"
#include <iostream>
using namespace std;

int main() {
    Heap<int> h1;
    h1.push(51);
    h1.push(6);
    h1.push(1);
    h1.push(38);
    h1.push(5);
    h1.push(10);
    h1.push(11);
    // while(!h1.empty()) {
    //     cout << "top: " << h1.top() << endl;
    //     cout << "size: " << h1.size() << endl;
    //     cout << "empty: " << h1.empty() << endl;
    //     h1.pop();
    // }
    // cout << "empty: " << h1.empty() << endl;

    Heap<string> h2;
    h2.push("dog");
    h2.push("bs");
    h2.push("abba");
    h2.push("joi");
    h2.push("9");
    while(!h2.empty()) {
        cout << "top: " << h2.top() << endl;
        h2.pop();
    }

    Heap<string> h3;
    

}