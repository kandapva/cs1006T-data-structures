/*
Linked list implementation of Queue
*/
#include <iostream>
using namespace std;

class Element
{
private:
    double real, imag;
    size_t key;
public:
    Element *next = NULL;
    // The below is called a constructor
    // It is used to initialise an object
    Element(double a, double b, size_t c) : real(a), imag(b), key(c) {}
    // The below is another constructor here we have overloaded
    // It is used to create dummy object (as in case with list)
    Element() {}
    // The below is called a destructor
    // It is used to clear space used by object once the object goes out of scope
    ~Element() {}
    // This is to print/iterate through the list
    void print()
    {
        if (imag < 0)
            cout << "(" << key << ") " << real << "-" << -1 * imag << "i" << endl;
        else
            cout << "(" << key << ") " << real << "+" << imag << "i" << endl;
    }
    bool isKey(int k)
    {
        if (key == k)
            return true;
        else
            return false;
    }
};

template <class T>
class Queue
{
    T *front;
    T *rear;
    T head;
    size_t N = -1;
public:
    Queue(){ 
        head.next = NULL;
        front = NULL;
        rear = NULL;
    }
    bool isQueueEmpty()
    {
        if (N==-1)
            return true;
        return false;
    }
    void EnQueue(T *elem)
    {
        if(N==-1){
            elem->next = head.next;
            head.next = elem;
            front = elem;
            rear = elem;
            N++;
        }
        else{
            rear->next = elem;
            rear = elem;
            N++;
        }
    }
    T* DeQueue()
    {
        T *tmp=front;
        if (isQueueEmpty())
        {
            std::cout << "illegal dequeue() operation" << std::endl;
        }
        else
        {
            head.next = front->next;
            front = head.next;
            N--;
        }
        return tmp;
    }
    T* getFront()
    {
        if (isQueueEmpty())
        {
            cout << "Queue Empty.." << endl;
        }
        return front;
    }
    ~Queue()
    {
    }
};

int main()
{
    Element *A = new Element(2, -10, 1);
    Element *B = new Element(1.0, 5.6, 2);
    Element *C = new Element(-3, 4, 3);
    Queue<Element> q1;
    q1.EnQueue(A);
    q1.EnQueue(B);
    q1.EnQueue(C);
    Element *tmp;
    tmp = q1.getFront();
    tmp = q1.DeQueue();
    tmp = q1.DeQueue();
    q1.EnQueue(B);
    tmp = q1.getFront();
    tmp->print();
    delete A;
    delete B;
    delete C;
    return 0;
}