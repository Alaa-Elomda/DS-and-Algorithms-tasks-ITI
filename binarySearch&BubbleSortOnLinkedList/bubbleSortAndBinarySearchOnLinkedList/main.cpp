#include <iostream>
#include "linkedlist.h"
#include "algorithm.h"

using namespace std;

int main()
{
    LinkedList<int> myList;
    int x=12;
    int y=7;
    int z=5;
    int a=11;
    int b=9;
    myList.Add(x);
    myList.Add(y);
    myList.Add(z);
    myList.Add(a);
    myList.Add(b);

    myList.Display();
    cout<<endl;

    //Bubble Sort
    cout<<"Bubble Sorting"<<endl;
    Algorithm::BubbleSort<int>(&myList);
    myList.Display();
    cout<<endl;

    //Binary Search
    cout<<"Search for 2"<<endl;
    Algorithm::BinarySearch<int>(&myList,2);

    cout<<endl;
    cout<<"Search for 9"<<endl;
    Algorithm::BinarySearch<int>(&myList,9);


    return 0;
}
