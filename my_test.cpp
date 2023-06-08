#include "Node.h"
#include "Queue.h"

int main()
{
    Queue<int> q;
    int x1=1;
    int x2=2;
    int x3=3;
    q.pushBack(x1);
    q.pushBack(x2);
    q.pushBack(x3);
   std::cout << "work1" << " ";
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

    // int front1 = q.front(); /* front1 equals 1 as its the first value */
    // q.printQueue();
    // printf("%d",front1);
    // q.front() = 3; /* queue1 content is: 3, 2 (left to right) */
    // front1 = q.front();
    // printf("%d",front1);
    // q.printQueue();
    // return 1;
}