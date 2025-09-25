#include <stdexcept>


template<typename DataType>
Stack<DataType>::Stack() {
    top=nullptr;
    length=0;
}

template<typename DataType>
Stack<DataType>::Stack(const Stack<DataType> &other) {
    DeepCopy(other);
}

template<typename DataType>
Stack<DataType>::~Stack() {
    deleteAll();
}

template<typename DataType>
void Stack<DataType>::deleteAll() {

    while (top != nullptr) {
        Node *dmw = top;
        top = top->next;
        delete dmw;
    }
    length=0;
}


template<typename DataType>
void Stack<DataType>::push(DataType Value) {
    Node *temp=new Node;
    temp->data=Value;
    temp->next=top;
    top=temp;
    length++;
}

template<typename DataType>
void Stack<DataType>::pop() {

    Node *temp=top;
    if (temp == nullptr) {
        throw std::out_of_range(" The Stack is Empty!!! \n nothing to delete");
    }
    top=temp->next;
    delete temp;

    length--;
}

template<typename DataType>
DataType Stack<DataType>::Peek() const {
    if (top==nullptr) {
        throw std::out_of_range("Nothing to see here!");
    }
    return top->data;
}

template<typename DataType>
int Stack<DataType>::size() const {
    return length;
}

template<typename DataType>
void Stack<DataType>::deepCopy(const Stack<DataType> &other) {
    if (other.top==nullptr) {
        this->top==nullptr;
        length=0;
        return;
    }
    top=new Node{other.top->data,nullptr};
    Node* otherNode=other.top->next;
    Node* thisNode=top;
    while (otherNode!=nullptr) {
        thisNode->next=new Node{otherNode->data,nullptr};
        otherNode=otherNode->next;
        thisNode=thisNode->next;

    }
    length=other.length;
}

template<typename DataType>
Stack<DataType> &Stack<DataType>::operator=(const Stack<DataType> &rhs) {
    deleteAll();
    DeepCopy(rhs);
    return *this;

}


