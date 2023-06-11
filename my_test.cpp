#include "Queue.h"
#include <iostream>
#include <string>
#include <cassert>


void setEvenToZero(int &i){

    if (i%2 == 0){

        i = 0;
    }

    else{

        i = 1;
    }
}

bool isEven(int i){

    if (i%2 == 0){

        return true;
    }

    else{

        return false;
    }
}

int main(){


  Queue<int> q;

  for (int i = 0; i<101; i++){

    q.pushBack(i);
  }
	
	std::cout << "push back is working" << std::endl;

  // print the queue

  for (int i : q){

    std::cout << i << std::endl;
  }

  std::cout << "print queue is working" << std::endl;
  std::cout << "iterator is working" << std::endl;

  if (q.size() == 101){

    std::cout << "size is working" << std::endl;

  }

    Queue<int> q2 = q;

    if (q.size() == q2.size()){

        std::cout << "size is working" << std::endl;
        
    }

   
    for (int i : q2){

    std::cout << i << std::endl;
  }
    
bool test = true;

    for (int i = 0; i<101; i++){

        int k = q2.front();
        int j = q.front();

        if (k!=j){

            test = false;
        }

        q.popFront();
        q2.popFront();
    }

    if (test == true){

        std::cout << "pop front is working" << std::endl;
    }

    for (int i = 0; i<101; i++){

        q.pushBack(i);
    }


    q2 = q;

    
    if (q.size() == q2.size()){

        std::cout << "size is working" << std::endl;
        
    }

    test = true;

    for (int i = 0; i<101; i++){

        int k = q2.front();
        int j = q.front();

        if (k!=j){

            test = false;
        }

        q.popFront();
        q2.popFront();
    }

    if (test == true){

        std::cout << "assignment front is working" << std::endl;
    }

    q.printQueue();
    q2.printQueue();

    for (int i = 0; i<101; i++){

        q.pushBack(i);
    }

    q2 = q;

    q.printQueue();
    q2.printQueue();

    Queue<int> q1 = filter(q,isEven);
    transform(q,setEvenToZero);

    std::cout << "--q1--" << std::endl;
    q.printQueue();
    std::cout << "--q2--" << std::endl;
    q1.printQueue();


    return 0;
}

/*

Queue<int>::Iterator it = q.begin();
std::cout << "work2" << " ";
it.printIT();
Queue<int>::Iterator end = q.end();
  std::cout << "work1" << " ";
// Iterate over the container and print the elements
while (it != end) {
   std::cout << *it << " ";
     ++it;
}
std::cout << std::endl;

// More test cases...

std::cout << "Tests passed!" << std::endl;

    // int front1 = q.front(); front1 equals 1 as its the first value
    // q.printQueue();
    // printf("%d",front1);
    // q.front() = 3; queue1 content is: 3, 2 (left to right) 
    // front1 = q.front();
    // printf("%d",front1);
    // q.printQueue();
    return 1;

*/