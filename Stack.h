#ifndef STACK_H
#define STACK_H


template<typename DataType>
class Stack {

private:
    struct Node {
        DataType data;
        Node* next;
    };
    Node* top;
    int length;

    void deepCopy(const Stack<DataType> &other);
    void deleteAll();
public:
    Stack();
    Stack(const Stack<DataType> &other);
    ~Stack();
    void push(DataType Value);
    void pop();
    DataType Peek() const;
    int size() const;
    Stack<DataType> &operator=(const Stack<DataType> &rhs);

};


#include "Stack.cpp"

#endif
