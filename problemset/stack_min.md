## 编写一个栈，可以以O(1)的时间复杂度返回栈中的最小值

```c++
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
/**
 * 编写一个栈，可以以O(1)的时间复杂度返回栈中的最小值
 */
class Stack_Min{
private:
    int min_value = 0x7fffffff;
    int* a = new int[100];
    int size = 100;
    int length = 0;
public:
    void push(int value) {
        if (length >= size){
            int *b = new int[size + 100];
            for (int i = 0;i < length;i++){
                b[i] = a[i];
            }
            delete[] a;
            a = b;
        }
        a[length++] = value;
        if (min_value > value){
//            cout<<"push(): min value changed from "<<min_value<<" to "<<value<<endl;
            min_value = value;
        }
    }
    void pop() {
        if (length == 0) {
            return;
        } else {
            min_value = a[0];
            for (int i = 0;i < length - 1;i++){
                if (min_value > a[i]) {
//                    cout<<"pop(): min value changed from "<<min_value<<" to "<<a[i]<<endl;
                    min_value = a[i];
                }
            }
            length--;
        }
    }
    int top() {
        if (length > 0) {
            return a[length - 1];
        } else {
            return -1;
        }
    }
    int min() {
        return min_value;
    }
};

```