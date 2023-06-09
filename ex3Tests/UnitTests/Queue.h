#ifndef _QUEUE_H
#define _QUEUE_H
#include <iostream>
#include <utility>
#include <exception>
#include <string>

//-----------------Queue class------------

template <class Element>
class Queue{

    private: 

        template <class NodeElement>
        struct Node{

            Element m_data;
            Node* m_next; 

            public:

                Node() = default; // why default?
                Node(const NodeElement& newElement){ // why not default?

                    m_data = newElement;
                    m_next = nullptr;
                }

                // Node(const Node& copyNode) = default;

                Node& operator=(const Node&) = default;

                ~Node() = default; // why default? 
                void print();
            };

        int m_size;
        Node<Element>* m_front;
        Node<Element>* m_rear;

public:

    Queue(); // why not default?

    Queue(const Queue& newQueue); //copy constructor
    ~Queue(); //dctor


    Queue<Element>& operator=(const Queue<Element>&); 
    // add == and != operators

    void pushBack(const Element newElement); //insert element to the end of the queue
    
    Element& front(); //return the first element in the queue
    
    const Element& front() const; //return the first element in the queue - const  // why reference?
    
    void popFront(); //remove the first element
    
    int size() const; //return the current size of the queue

    //template <class C>
    //Queue<Element> filter(const Queue<Element> queue ,C comparator); // this function should be outside the class 
    //friend Queue<Element> filter(const Queue<Element> &queue ,bool(*(Condition))(C))
    //template <class O>
    //friend void transform(Queue<Element> &queue,bool(*(Operation))(O));
    
    class Iterator;
    Iterator begin() const;
    Iterator end() const;

    class ConstIterator;
    ConstIterator cbegin() const;
    ConstIterator cend() const;

    // for debugging
    void printQueue() const;


    // Exeptions zone
    class EmptyQueue{};

    

};






//---------- QUEUE -------------------------

template <class Element>
Queue<Element>::Queue(){
    m_size  = 0;
    m_front = nullptr;
    m_rear = nullptr;
}

template <class Element>
Queue<Element>::Queue(const Queue& copyQueue){


    if (this == &copyQueue){

        return;
    }

    m_size = 0;
    m_front = nullptr;
    m_rear = nullptr;

    //typename Queue<Element>::ConstIterator it = copyQueue.cbegin();


    try {

        for (Element it : copyQueue){

            try {

                this->pushBack(it);

            }catch(std::bad_alloc& e){
            
                delete this;
            }

        }

    }catch (typename Queue<Element>::Iterator::InvalidOperation& o){

        std::cout << "Iterator error" << std::endl;
        
    }catch (typename Queue<Element>::ConstIterator::InvalidOperation& o){

        std::cout << "Iterator error" << std::endl;
        
    }

    /*for (it = copyQueue.cbegin();  it != copyQueue.cend();){

        //try{

           it++;

        //}catch (typename Queue<Element>::Iterator::InvalidOperation& o){

            //std::cout << "Iterator error" << std::endl;
        //}
    
        //try{

            this->pushBack(*it);

        //}catch(std::bad_alloc& e){
        
            //delete this;
        //}  
    }*/

    //delete &it;
}


template <class Element>
Queue<Element>::~Queue(){

    if (m_front == nullptr)
    {
        return;
    }

    typename Queue<Element>::Iterator it = this->begin();

    try {

        for (Element it : *this){
            
            delete &it;
        }
    
    } catch (typename Queue<Element>::Iterator::InvalidOperation& o){

        std::cout << "Iterator error" << std::endl;
        
    }catch (typename Queue<Element>::ConstIterator::InvalidOperation& o){

        std::cout << "Iterator error" << std::endl;
        
    }

    /*

    for (it = this->begin();  it != this->end();){
        
        //try{

           it++;

        //}catch (typename Queue<Element>::Iterator::InvalidOperation& o){

            std::cout << "Iterator error" << std::endl;
        //}
    
        delete &it;
    }  */

    delete m_front;
    delete m_rear;
}

template <class Element>
Queue<Element>& Queue<Element>::operator=(const Queue<Element>& copyQueue){

    if (this == &copyQueue){

        return *this;
    }

    m_size = copyQueue.m_size;

    delete this;

    m_size = 0;
    m_front = nullptr;
    m_rear = nullptr;

    try{

        for (Element it : copyQueue){

            try {

                this->pushBack(it);

            }catch(std::bad_alloc& e){
                
                delete this;
            }

        }
    }catch (typename Queue<Element>::Iterator::InvalidOperation& o){

        std::cout << "Iterator error" << std::endl;
        
    }catch (typename Queue<Element>::ConstIterator::InvalidOperation& o){

        std::cout << "Iterator error" << std::endl;
        
    }

    
    /*for (it = copyQueue.begin();  it != copyQueue.end();){

        //try{

           it++;

        //}catch (typename Queue<Element>::Iterator::InvalidOperation& o){

            //std::cout << "Iterator error" << std::endl;
        //}
    
        //try{

            this->pushBack(*it);

        //}catch(std::bad_alloc& e){
        
            //delete this;
        //}  
    }

    
    
    Node<Element>* currentCopy = copyQueue.m_front;
    Node<Element>* currentQueue = m_front;
  
    while (currentCopy != nullptr) {
        
        currentQueue->m_data = currentCopy->m_data;
        currentCopy = currentCopy->m_next;
        currentQueue = currentQueue->m_next;
    }

    delete currentCopy; // why delete?
    delete currentQueue; // why delete?
    delete &it;*/

    return *this;
}
      

template <class Element>
void Queue<Element>::pushBack(const Element newElement){

   //the new throw exception
    Node<Element>* newNode = new Node<Element>(newElement);

    if (m_front ==  nullptr){

        m_front = newNode;
        m_rear = newNode;
    } 
    else{

        m_rear->m_next = newNode;
        m_rear = newNode; // why not m_rear = nullptr?
    }

    m_size++;

}

template <class Element>
Element& Queue<Element>::front(){

    if (m_front == nullptr){

        throw EmptyQueue();
    }

    return(m_front->m_data);
}

template <class Element>
const Element& Queue<Element>::front() const{

    if ( m_front == nullptr){

        throw EmptyQueue();
    }
    return(m_front->m_data); 
}

template <class Element>
void Queue<Element>::popFront(){

    if (m_front == nullptr || m_size == 0){ 

        throw EmptyQueue();
    }

    Node<Element>* nodeToDelete = m_front; 
    m_front = m_front->m_next;
    delete nodeToDelete;
    m_size--; // check this function
}

template <class Element>
int Queue<Element>::size() const{

    return m_size;
}


template <class Element>
typename Queue<Element>::Iterator Queue<Element>::begin() const{

    return Iterator(this);
}

template <class Element>
typename Queue<Element>::Iterator Queue<Element>::end() const{

    Iterator t = (this);
    for(int i = 0; i < m_size; i++){
        t++;
    }
    return(t);
}


template <class Element>
typename Queue<Element>::ConstIterator Queue<Element>::cbegin() const{

    return ConstIterator(this);
}

template <class Element> // add exception -------------------------------------------------------------------------
typename Queue<Element>::ConstIterator Queue<Element>::cend() const{

    ConstIterator t = (this);
    for(int i = 0; i < m_size; i++){
        t++;
    }
    return(t);
}


template<class Element, class C>
Queue<Element> filter(const Queue<Element> &queue ,C comparator){ // const because we dont want to change the queue on this operation, and we have const iterator

    Queue<Element> filteredQueue; // empty queue of the filtered elements
    
    try {

        for (Element element : queue) // running with the const iterator
        {
            if(comparator(element)){

                try{
                    filteredQueue.pushBack(element);
                }catch(std::bad_alloc& e){
                    
                    delete &filteredQueue;
                }
            }
        }

    }catch (typename Queue<Element>::Iterator::InvalidOperation& o){
            
            std::cout << "Iterator error" << std::endl;
            
    }catch (typename Queue<Element>::ConstIterator::InvalidOperation& o){

        std::cout << "Iterator error" << std::endl;
        
    }

    
    return filteredQueue;
}


template <class Element, class O>
void transform(Queue<Element> &queue,O operation){


    /*typename Queue<Element>::Iterator it = queue.begin();

    for (it = queue.begin(); it != queue.end(); it++){

        operation(*it);
    }*/

    try{

        for (Element &element : queue) // running with the iterator
        {
            operation(element);
        }

    }catch (typename Queue<Element>::Iterator::InvalidOperation& o){
            
        std::cout << "Iterator error" << std::endl;
            
    }catch (typename Queue<Element>::ConstIterator::InvalidOperation& o){

        std::cout << "Iterator error" << std::endl;
        
    }

    /*for (it = queue.begin();  it != queue.end();){
    
        //try{

           it++;

        //}catch (typename Queue<Element>::Iterator::InvalidOperation& o){

            //std::cout << "Iterator error" << std::endl;
        //}
    
        operation(*it);
    }*/
}

//--------------Iterator------------------


//--------------iterator class----------------

template <class Element>
class Queue<Element>::Iterator{

    private:

        Iterator(const Queue<Element>* queue); // check this out
        Node<Element>* m_current;
        friend class Queue;

    public:
    
        Iterator(const Iterator& copyIterator);
        ~Iterator() = default; // we dont need to delete the iterator, because we dont allocate memory for it

        Element& operator*(); // we can change the value of the element
        Queue<Element>::Iterator& operator++();
        Queue<Element>::Iterator operator++(int);

        bool operator==(const Iterator&) const; // const because we dont want to change the iterator on this operation
        bool operator!=(const Iterator&) const; // const because we dont want to change the iterator on this operation

        class InvalidOperation{}; // we can throw this exception if we want to do something that is not allowed

};


template <class Element>
Queue<Element>::Iterator::Iterator(const Queue<Element>* queue){ // get a pointer to the queue, so we send the address, mean send the reference

    if(queue == nullptr){

        throw InvalidOperation();
    }

    m_current = queue->m_front;

}

template <class Element>
Queue<Element>::Iterator::Iterator(const Iterator& copyIterator){
     
    if(copyIterator.m_current == nullptr){

        throw Queue<Element>::Iterator::InvalidOperation();
    }

    m_current = copyIterator.m_current;
}

template <class Element>
typename Queue<Element>::Iterator& Queue<Element>::Iterator::operator++(){ // prefix

    if (m_current == nullptr){ // if we are at the end of the queue

        throw Queue<Element>::Iterator::InvalidOperation();
    }
    else {

        m_current = m_current->m_next;
    }
    
    return *this;

}

template <class Element>
typename Queue<Element>::Iterator Queue<Element>::Iterator::operator++(int){
    
    if(m_current == nullptr){

        Queue<Element>::Iterator::InvalidOperation();
    }

    Iterator temp(*this);

    try{
            
        ++(*this);

    }catch (Queue<Element>::Iterator::InvalidOperation& e){
            
        Queue<Element>::Iterator::InvalidOperation();
    }

    return temp;
}

template <class Element>
bool Queue<Element>::Iterator::operator==(const Iterator& compareIterator) const{
  
    /*if(m_current == nullptr && compareIterator.m_current == nullptr){ // we don't want to throw exception here, because we want to check if the iterators are equal so we can stop the loop

        throw Queue<Element>::Iterator::InvalidOperation();
    }*/
     
    return (this->m_current == compareIterator.m_current);
}

template <class Element>
bool Queue<Element>::Iterator::operator!=(const Iterator& compareIterator) const{
     
    //if(m_current == nullptr || compareIterator.m_current == nullptr){

        //throw Queue<Element>::Iterator::InvalidOperation();
    //}

    return !((*this) == compareIterator);

}

template <class Element>
Element& Queue<Element>::Iterator::operator*(){

    if(m_current == nullptr){

        throw Queue<Element>::Iterator::InvalidOperation();
    }

    return (m_current->m_data);
}


template <class Element>    
void Queue<Element>::printQueue() const {
    
    Node<Element>* current = m_front;
    
    while (current != nullptr) {
   
        std::cout << current->m_data << " ";
        current = current->m_next;
    }
     
    std::cout << "size is " << m_size << " ";
    std::cout << std::endl;
}



//---------------const iterator class---------

template <class Element>
class Queue<Element>::ConstIterator{

 private:
    
    const Node<Element>* m_current;
    ConstIterator(const Queue<Element>* queue);
    friend class Queue;

 public:
    
    ConstIterator(const Iterator& copyIterator);
    ~ConstIterator() = default;
    const Element& operator*() const; // we cant change the value of the element - const iterator
    Queue<Element>::ConstIterator& operator++();
    Queue<Element>::ConstIterator operator++(int);
    bool operator==(const ConstIterator&) const;
    bool operator!=(const ConstIterator&) const; 

    class InvalidOperation{};

};

//--------------const Iterator------------------


template <class Element>
Queue<Element>::ConstIterator::ConstIterator(const Queue<Element>* queue){
    
    if(queue == nullptr){

        throw Queue<Element>::ConstIterator::InvalidOperation();
    }
    
    m_current = queue->m_front;

}

template <class Element>
Queue<Element>::ConstIterator::ConstIterator(const Iterator& copyIterator){

    if(copyIterator.m_current == nullptr){

        throw Queue<Element>::ConstIterator::InvalidOperation();
    }

    m_current = copyIterator.m_current;


}

template <class Element>
typename Queue<Element>::ConstIterator& Queue<Element>::ConstIterator::operator++(){
    
    if(m_current == nullptr){

        throw Queue<Element>::ConstIterator::InvalidOperation();
    }

    if (m_current == nullptr){

        throw Queue<Element>::ConstIterator::InvalidOperation();
    }
    else {

        m_current = m_current->m_next;
    }

    return *this;

}

template <class Element>
typename Queue<Element>::ConstIterator Queue<Element>::ConstIterator::operator++(int){

    if(m_current == nullptr){

        throw Queue<Element>::ConstIterator::InvalidOperation();
    }
    
    ConstIterator temp = *this;

    try {
            
        ++(*this);
    
    } catch (Queue<Element>::ConstIterator::InvalidOperation& e){
            
        throw Queue<Element>::ConstIterator::InvalidOperation();
    }

    return temp;

}

template <class Element>
bool Queue<Element>::ConstIterator::operator==(const ConstIterator& compareIterator) const{
     
    /*if(compareIterator.m_current == nullptr){

        throw Queue<Element>::ConstIterator::InvalidOperation();
    }*/
    
    return (m_current == compareIterator.m_current);
}

template <class Element>
bool Queue<Element>::ConstIterator::operator!=(const ConstIterator& compareIterator) const{
     
    return !((*this) == compareIterator);
}

template <class Element>
const Element& Queue<Element>::ConstIterator::operator*() const{
    
    if(m_current == nullptr){

        throw Queue<Element>::ConstIterator::InvalidOperation();
    }

    return (m_current->m_data);
}



#endif

