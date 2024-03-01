/*
    Example of iterators in list
*/
#include <iostream> 
#include <iterator> // for iterators 
#include <vector> // for vectors 
#include <list> //for lists
using namespace std; 
int main() 
{ 
    vector<int> ar = { 10, 20, 30, 40, 50 }; 
      
    // Declaring iterator to a vector 
    vector<int>::iterator ptr = ar.begin(); 
    cout << "The position of iterator at start : "; 
    cout << *ptr << " " << " Address " << &*ptr <<endl;  
    vector<int>::iterator ptr1 = ar.end(); 
    cout << "The position of iterator at end : "; 
    cout << *ptr1 << " " << " Address " << &*ptr1 <<endl; 
      
    // Using advance() to increment iterator position 
    // points to 4 
    advance(ptr, 3); 
      
    // Displaying iterator position 
    cout << "The position of iterator after advancing is : "; 
    cout << *ptr << " " <<endl; 
 
    
    for(vector<int>::iterator itr = ar.begin(); itr != ar.end(); advance(itr,1))
    {
        cout << *itr << endl;
    }
    
    list<int> lst = {11, 22, 33, 44, 55};
    // Declaring iterator to a list 
    list<int>::iterator ptrl = lst.begin(); 
    cout << "The position of iterator at start : "; 
    cout << *ptrl << " " << " Address " << &*ptrl <<endl; 
    list<int>::iterator ptr1l = lst.end(); 
    cout << "The position of iterator at end : "; 
    cout << *ptr1l << " " << " Address " << &*ptr1l <<endl;  
    
    for(list<int>::iterator itr = lst.begin(); itr != lst.end(); advance(itr,1))
    {
        cout << *itr << endl;
    }
    
    return 0; 
      
} 