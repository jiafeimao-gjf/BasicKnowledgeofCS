## 编写一个栈，可以以O(1)的时间复杂度返回栈中的最小值

```cpp
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
/**
 * 编写一个栈，可以以O(1)的时间复杂度返回栈中的最小值。
    完全自己实现。
 */
class Stack_Min{
private:
    int min_value = 0x7fffffff;
    int* a = new int[100];
    int size = 100;
    int length = 0;
public:
    void push(int value) {
        if (length >= size){ // 空间扩容
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

## 剑指offer 中的要求push()、pop()、min() 的事件复杂度都为O(1)
### 代码：
```cpp
/**
    借助c++的内置栈实现
*/
template <typename T> class StackWithMin{
public:
    StackWithMin() {}
    virtual ~StackWithMin() {}

    T& top()
    const T& top() const;

    void push(const T& value);

    void pop();

    const T& min const;

    bool empty() const;
    size_t size() const;

private:
    std::stack<T> m_data;
    std::stack<T> m_min;    
}
/**
    入栈操作
*/
template <typename T> void StackWithMin<T>::push(const T& value) {
    m_data.push(value);
    // 最小值栈为空或者当前值小于栈顶的数值
    if (m_min.size() == 0 || value < m_min.top) {
        m_min.push(value);
    } else {// 否则
        m_min.push(m_min.top());// 栈顶数据复压栈
    }
}

/**
    出栈操作
*/
template <typename T> void StackWithMin:pop(){
    // 断言
    assert(m_data.size() > 0 && m_min.size() > 0);

    m_data.pop();// 数据栈出栈
    m_min.pop(); // 感觉这里不对劲呀，因为入栈时有复入栈所以，这里要出栈，保证最小值同步
}

/**
    求最小值操作
*/
template <typename T> const T& StackWithMin::min() const {
    assert(m_data > 0 && m_min.size() > 0);
    return m_min.top();// 直接返回最小值栈顶元素
}

/**
    求栈顶元素操作
*/
template <typename T> T& StackWithMin<T>::top()
{
    return m_data.top();
}

template <typename T> const T& StackWithMin<T>::top() const
{
    return m_data.top();
}

template <typename T> bool StackWithMin<T>::empty() const
{
    return m_data.empty();
}

template <typename T> size_t StackWithMin<T>::size() const
{
    return m_data.size();
}
```