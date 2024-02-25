/*
Linked list implementation of Stack
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
class Stack{
T *top;
T head;
size_t N;
public:
    Stack(){
        top = &head;
        head.next = NULL;
        N=0;
    }
    bool isStackEmpty(){
        if(N==0)
            return true;
        return false;
    }
    void push(T *elem){
        elem->next = head.next;
        head.next = elem;
        top = elem;
        N++;
    }
    T* pop(){
        T *tmp;
        tmp = top;
        if(N==0){
            std::cout << "illegal pop() operation" << std::endl;
            tmp = NULL;
        }
        else 
        {
            head.next = top->next;
            N--;
            top = head.next;
        }
        return tmp;
    }
    T* getTop(){
        return top;
    }
    ~Stack(){}

};

int main()
{
    Element *A = new Element(2, -10, 1);
    Element *B = new Element(1.0, 5.6, 2);
    Element *C = new Element(-3, 4, 3);
    Stack<Element> s1;
    s1.push(A);
    Element *tmp;
    tmp = s1.getTop();
    tmp->print();
    //s1.push(A);
    s1.push(B);
    s1.push(C);
    cout << "Get TOP.." <<endl; 
    tmp = s1.getTop();
    tmp->print();
    cout << "pop()" << endl;
    tmp = s1.pop();
    tmp->print();
    cout << "pop()" << endl;
    tmp = s1.pop();
    tmp->print();
    cout << "Is Stack Empty" << s1.isStackEmpty() << endl;
    cout << "pop()" << endl;
    tmp = s1.pop();
    tmp->print();
    cout << "Is Stack Empty" << s1.isStackEmpty() << endl;
    tmp = s1.pop();
    return 0;
}