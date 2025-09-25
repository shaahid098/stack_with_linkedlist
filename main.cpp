#include <iostream>
#include "Stack.h"
#include <stdexcept>
int main() {

    Stack<int> *myStack= new Stack<int>;

    myStack->push(8);
    std::cout << "The top is: " << myStack->Peek() << std::endl;
    myStack->push(66);
    std::cout << "The top is: " << myStack->Peek() << std::endl;
    myStack->push(42);
    std::cout << "The top is: " << myStack->Peek() << std::endl;

    Stack<int> myOtherStack= *myStack;

    myOtherStack.pop();
    myOtherStack.push(99);
    std::cout << "The top of my other stack should be 99 and it is: " << myOtherStack.Peek() << std::endl;
    std::cout << "The top of my other stack should be 42 and it is: " << myStack->Peek() << std::endl;



    try {
        myStack->pop();
        std::cout << "The top is: " << myStack->Peek() << std::endl;
        myStack->pop();
        std::cout << "The top is: " << myStack->Peek() << std::endl;
        myStack->pop();
        std::cout << "The top is: " << myStack->Peek() << std::endl;
        myStack->pop(); //should throw an error
        std::cout << "The top is: " << myStack->Peek() << std::endl;

    } catch (std::out_of_range &err) {
        std::cerr << err.what() << std::endl;
    }

    myStack->push(1);
    myStack->push(2);
    myStack->push(3);
    myStack->push(4);

    Stack<int> *RuchasStack= new Stack<int>;
    RuchasStack=myStack;
    delete myStack;




    return 0;
}

