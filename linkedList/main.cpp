#include <iostream>

#include "LinkedList.h"


using namespace std;

int main()
{
    LinkedList<int> myList;

    myList.Add(3);
    myList.Add(5);
    myList.Add(7);
    myList.Add(9);
    myList.Add(11);

    cout<<"The First List :"<<endl;
    myList.Display();
    cout<<endl;

    cout<<"Is Number 7 in the List? "<<endl;
    if(myList.Search(7))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }

    cout<<"If it's Found,then remove it from the List: "<<endl;
    myList.Remove(7);
    myList.Display();
    cout<<endl;


///////////test GetCount Function
    cout<<"Number of nodes in the First List: "<<myList.GetCount()<<endl;

    LinkedList<int> myList2;
    cout<<"Number of nodes in the Second List: "<<myList2.GetCount()<<endl;

    cout<<"The Second List :"<<endl;
    myList2.Add(5);
    myList2.Display();
    cout<<endl;
    cout<<"Number of nodes in the Second List: "<<myList2.GetCount()<<endl;


    ///////////test GetDataByIndex Function
    cout<<"Data at index 1 in the First List is: "<<myList.GetDataByIndex(1)<<endl;
    //cout<<"Data at index 50 is: "<<myList.GetDataByIndex(50)<<endl;

///////////test InsertAfter Function
    cout<<endl;
    myList.InsertAfter(12,3);
    cout<<"Insert Number 12 after Number 3 in the First List: "<<endl;
    myList.Display();
    cout<<endl;
    //trying to add after not existing data(will be added at the end of the list)
    myList.InsertAfter(20,4);
    cout<<"Try to add Number 20 after a non-existing Number  in the First List: "<<endl;
    myList.Display();


    ///////////test Reverse Function
    LinkedList<int> myList3;

    myList3.Add(10);
    myList3.Add(20);
    myList3.Add(30);
    myList3.Add(40);
    myList3.Add(50);

    cout<<endl;
    cout<<endl;
    cout<<"The Third List :"<<endl;
    myList3.Display();

    LinkedList<int>* revMyList3 = myList3.Reverse();
    cout<<endl;
    cout<<"The Third List reversed :"<<endl;
    revMyList3->Display();
    cout<<endl;
    cout<<"The original Third List:"<<endl;
    myList3.Display();
    cout<<endl;


///////////test InPlaceReverse Function
    LinkedList<int> myList4;

    myList4.Add(100);
    myList4.Add(200);
    myList4.Add(300);
    myList4.Add(400);
    myList4.Add(500);

    cout<<endl;
    cout<<"The Fourth List :"<<endl;
    myList4.Display();


    myList4.InPlaceReverse();
    cout<<endl<<"the reversed Forth List: "<<endl;
    myList4.Display();
    cout<<endl;


    return 0;
}
