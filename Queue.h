#ifndef _QUEUE_H
#define _QUEUE_H
#include <iostream>
#include <utility>

//-----------------Queue class------------

template <class Element>
class Queue{

    template <class NodeElement>
    struct Node{
        Element m_data;
        Node* m_next; 
    public:
        Node() = default;
        Node(const NodeElement& newElement){
            m_data = newElement;
            m_next = nullptr;
    }
        Node& operator=(const Node&) = default;
        ~Node() = default;
        void print();
    };

int m_size;
Node<Element>* m_front;
Node<Element>* m_rear;

public:

    Queue();
    //copy constructor
    Queue(const Queue& newQueue);
    //dctor
    ~Queue();
    Queue<Element>& operator=(const Queue<Element>&);
    //insert element to the end of the queue
    void pushBack(const Element newElement);
    //return the first element in the queue
    Element& front();
    //return the first element in the queue - const
    const Element& front() const;
    //remove the first element
    void popFront();
    //return the current size of the queue
    int size() const;
    template <class Condition>
    Queue<Element> filter(const Queue<Element> queue,const Condition c);
    template <class Operation>
    void tranform(Queue<Element>& queue,const Operation o);
    
    class Iterator;
    Iterator begin();
    Iterator end();
    void printQueue() const;

};

//--------------iterator class----------------

template <class Element>
class Queue<Element>::Iterator{
    const Node<Element>* m_current;
    Iterator(const Queue<Element>* queue);
    friend class Queue;
public:
    
    Iterator(const Iterator& copyIterator);
    ~Iterator() = default;
    Iterator& operator=(const Iterator&);
    const Element& operator*() const;
    Queue<Element>::Iterator& operator++();
    Queue<Element>::Iterator operator++(int);
    bool operator==(const Iterator&) const;
    bool operator!=(const Iterator&) const; 
    void printIT();  

};

//---------------const iterator class---------

// template <class Element>
// class Queue<Element>::Iterator{
//     const Node<Element>* m_current;
//     Iterator(const Queue<Element>* queue);
//     friend class Queue;
// public:
    
//     Iterator(const Iterator& copyIterator);
//     ~Iterator() = default;
//     Iterator& operator=(const Iterator&);
//     const Element& operator*() const;
//     Queue<Element>::Iterator& operator++();
//     Queue<Element>::Iterator operator++(int);
//     bool operator==(const Iterator&) const;
//     bool operator!=(const Iterator&) const; 
//     void printIT();  

// };

//---------- QUEUE -------------------------

template <class Element>
Queue<Element>::Queue(){
    m_size  = 0;
    m_front = nullptr;
    m_rear = nullptr;
}

template <class Element>
Queue<Element>::Queue(const Queue& copyQueue){

    m_size = 0;
    m_front = nullptr;
    m_rear = nullptr;
    Node<Element>* currentCopy = copyQueue.m_front;
  
        while (currentCopy != nullptr) {

            pushBack(currentCopy->m_data);
            currentCopy = currentCopy->m_next;
        }
   
    delete currentCopy;

}

template <class Element>
Queue<Element>::~Queue(){
    
    while (m_front != nullptr) {

        Node<Element>* temp = m_front;
        m_front = m_front->m_next;
        delete temp;
   }
}

template <class Element>
Queue<Element>& Queue<Element>::operator=(const Queue<Element>& copyQueue){

    m_size = copyQueue.m_size;
    Node<Element>* currentCopy = copyQueue.m_front;
    Node<Element>* currentQueue = m_front;
  
        while (currentCopy != nullptr) {
        
            currentQueue->m_data = currentCopy->m_data;
            currentCopy = currentCopy->m_next;
            currentQueue = currentQueue->m_next;
        }

    delete currentCopy;
    delete currentQueue;

return *this;

}
      

template <class Element>
void Queue<Element>::pushBack(const Element newElement){

    Node<Element>* newNode = new Node<Element>(newElement);
    if (m_front ==  nullptr){

        m_front = newNode;
        m_rear = newNode;
    } 
    else{

        m_rear->m_next = newNode;
        m_rear = newNode;
    }

    m_size++;

}

template <class Element>
Element& Queue<Element>::front(){
    //if ( m_front == nullptr){ }
    return(m_front->m_data);
}

template <class Element>
const Element& Queue<Element>::front() const{
    //if ( m_front == NULL){}
    return(m_front->m_data); 
}

template <class Element>
void Queue<Element>::popFront(){

//     if (m_front == NULL){}

    Node<Element>* nodeToDelete = m_front; 
    m_front = m_front->m_next;
    delete nodeToDelete;
    m_size--;
}

template <class Element>
int Queue<Element>::size() const{

    return m_size;
}


template <class Element>
typename Queue<Element>::Iterator Queue<Element>::begin(){
    return Iterator(this);
}

template <class Element>
typename Queue<Element>::Iterator Queue<Element>::end(){
    Iterator t = (this);
    for(int i = 0; i < m_size; i++){
        t++;
    }
    return(t);

}

template <class Element, class Condition>
Queue<Element> filter(const Queue<Element> queue,const Condition c){

    Queue<Element> filteredQueue();
    typename Queue<Element>::Iterator it = (queue);
    for (it = queue.begin();  it != queue.end(); it++)
    {
        if( c(*it)){
            filteredQueue.pushback(*it);
        }
    }

    return (filteredQueue);

}


template <class Element, class Operation>
void tranform(Queue<Element>& queue,const Operation o){

    typename Queue<Element>::Iterator it = (queue);
    for (it = queue.begin();  it != queue.end(); it++)
    {
        o(*it);
    }
}

//--------------Iterator------------------

template <class Element>
void Queue<Element>::Iterator::printIT(){
 std::cout << m_current->m_data << " ";

}


template <class Element>
Queue<Element>::Iterator::Iterator(const Queue<Element>* queue){

    m_current = queue->m_front;

}

template <class Element>
Queue<Element>::Iterator::Iterator(const Iterator& copyIterator){

    m_current = copyIterator.m_current;


}

template <class Element>
typename Queue<Element>::Iterator& Queue<Element>::Iterator::operator=(const Iterator& other){

    m_current.m_data = other.m_current.m_data;

}

template <class Element>
typename Queue<Element>::Iterator& Queue<Element>::Iterator::operator++(){

    m_current = m_current->m_next;
    return *this;

}

template <class Element>
typename Queue<Element>::Iterator Queue<Element>::Iterator::operator++(int){

    Iterator temp = *this;
    ++(*this);
    return temp;

}

template <class Element>
bool Queue<Element>::Iterator::operator==(const Iterator& compreIterator) const{
     
    return (m_current == compreIterator.m_current);


}

template <class Element>
bool Queue<Element>::Iterator::operator!=(const Iterator& compreIterator) const{
     
    return !(*this == compreIterator);


}

template <class Element>
const Element& Queue<Element>::Iterator::operator*() const{

    return (m_current->m_data);
}





template <class Element>    
void Queue<Element>::printQueue() const {
    
    Node<Element>* current = m_front;
    
        while (current != nullptr) {
   
            std::cout << current->m_data << " ";
            current = current->m_next;
    }
     
    std::cout << m_size << " ";
    std::cout << std::endl;
}


#endif

