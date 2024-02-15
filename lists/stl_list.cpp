// C++ program to demonstrate the implementation of List
#include <iostream>
#include <iterator>
#include <list>
using namespace std;
 
// function for printing the elements in a list
template<typename T>
void print_list(list<T> g)
{
    list<T>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << endl;
}
 
// Driver Code
int main()
{
 
    list<int> list1, list2;
 
    for (int i = 0; i < 10; ++i) {
        list1.push_back((i * 2 + 1));
        list2.push_front((i * 3 -2));
    }
    cout << endl << "List 1 is : ";
    print_list(list1);

    cout << endl << "List 2 is : ";   
    print_list(list2);
 
    cout << "list1.front() : " << list1.front() << endl;
    cout << "list1.back() : " << list1.back() << endl;
 
    return 0;
}