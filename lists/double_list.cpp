/*
Doubly Linked list implementation using classes in C++
*/
#include <iostream>

using namespace std;

// Below is the class definition to store a complex number
// It has three private variables real, imag and key (unique identifier)
// The member functions are print() and Check the key()
class Element{
    private:
    double real, imag;
    size_t key;
    public:
    Element *next=NULL;
    Element *prev=NULL;
    // The below is called a constructor 
    // It is used to initialise an object
    Element(double a, double b,size_t c) : real(a), imag(b), key(c){}
    // The below is another constructor here we have overloaded
    // It is used to create dummy object (as in case with list)
    Element(){}
    // The below is called a destructor 
    // It is used to clear space used by object once the object goes out of scope
    ~Element(){}
    // This is to print/iterate through the list
    void print(){
        if(imag<0)
            cout <<"(" << key <<") "<< real << "-" << -1*imag <<"i" <<endl;
        else
            cout <<"(" << key <<") "<< real << "+" << imag <<"i"<<endl;
    }
    bool isKey(int k){
        if(key == k)
            return true;
        else 
            return false;
    }
};
// Below class implements single linked list with following operations
//      1) insertAtBegin
//      2) insertAtEnd
//      3) insertElementatK
//      4) Find with key
//      5) deleteElement
template <class T>
class DoubleList{
    T head, tail;
    size_t N;
    public:
    // The below function is the constructor for the list creation
    DoubleList(){
        head.next = &tail;
        tail.prev = &head;
        N = 0;
    }
    // Below function inserts new element at begining
    void insertAtBegin(T *new_element){
        new_element->prev = &head;
        new_element->next = head.next;
        (new_element->next)->prev = new_element;
        head.next = new_element;
        N++;
    }
    // Below function inserts new element at end
    void insertAtEnd(T *new_element){
        T *elem;
        T *tmp;
        elem = head.next;
        tmp = elem->next;
        while(tmp->next!=NULL)
        {
            elem = elem->next;
            tmp = elem->next;
        }
        new_element->next = tmp;
        elem->next = new_element;
        N++;
    }
    void print_list(){
        T *elem;
        elem = head.next;
        while(elem->next!=NULL)
        {
           elem->print(); 
           elem = elem->next;
        }
    }
    // Finds the data with key and returns that object
    bool find(size_t key){
        T *elem;
        elem = head.next;
        while(elem->next!=NULL)
        {
           if(elem->isKey(key)){
               elem->print();// prints the element if found
               return true;
           } 
           elem = elem->next;
        }
        return false;
    }
    // Inserts the element at kth location
    void insertElementatK(T *new_element, size_t K){
        if(K==1)
            insertAtBegin(new_element);
        if(K>1 && K<=N){
            T *elem;
            elem = &head;
            for(int i=1;i<K;i++)
                elem = elem->next;
            new_element->next = elem->next;
            elem->next = new_element;
            N++;
        }
        else{
             cout << "Invalid location" <<endl; 
        }
    }
    // Deletes the element with "key"
    void deleteElement(int key){
        T *prev_elem, *elem, *next_elem;
        prev_elem = &head;
        elem = prev_elem->next;
        next_elem = elem->next;
        while(next_elem->next!=NULL)
        {
           if(elem->isKey(key)){
               prev_elem->next = elem->next;
               break;
           } 
            prev_elem = elem;
            elem = elem->next;
            next_elem = elem->next;
        }
        if(elem->isKey(key)){
               prev_elem->next = elem->next;
           }
    }
    void reverse_list(){
        // Your code goes here
    }
    // return the list size (N is not modifiable by any other piece of code)
    size_t get_list_size(){return N;};
    ~DoubleList(){
    }
};

int main()
{
    Element *A = new Element(2,-10,1);
    Element *B = new Element(1.0,5.6,2);
    Element *C = new Element(-3,4,3);
    DoubleList<Element> l1;
    l1.insertAtBegin(A);
    cout << "Inserted  element at " << l1.get_list_size() <<endl;
    l1.insertAtBegin(B);
    cout << "Inserted  element at " << l1.get_list_size() <<endl;
    //l1.print_list();
    l1.insertAtEnd(C);
    cout << "Inserted  element at " << l1.get_list_size() <<endl;
    l1.print_list();
    cout << "Find 1 : " << l1.find(1)<<endl;
    cout << "Find 4 : " << l1.find(4)<<endl;
    //l1.deleteElement(3);
    l1.print_list();
    cout << "Find 3 : " << l1.find(3)<<endl;
    Element *D = new Element(-11,4,5);
    l1.insertElementatK(D,3);
    l1.print_list();
    return 0;
}
