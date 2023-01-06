#include <iostream>
#ifndef ALGORITHM_H
#define ALGORITHM_H

using namespace std;

#include "node.h"
#include "linkedlist.h"


class Algorithm
{
public:
    //swap function
    template<class T>
    static void Swap(T &first, T &second)
    {
        T temp = first;
        first = second;
        second = temp;
    }

    //get middle node(for Binary search)
    template<class T>
    static Node<T> * GetMiddle(Node<T> *min, Node<T> *max)
    {
        Node<T> *current = min;
        Node<T> *midIndex = min;
        int count = 0;
        int i=0;
        while(current != max)
        {
            current = current->Next;
            count++;
        }
        while (i < count/2)
            {
                midIndex=midIndex->Next;
                i++;
            }
        return midIndex;
    }

    //Bubble Sort
    template<class T>
    static void BubbleSort(LinkedList<T> *list)
    {
        int iterations = 0;
        int sorted = 0; //flag for check if it's sorted

        Node<T> *current = list->head;

        while(current != NULL && sorted == 0)
        {
            Node<T> *index = list->head;
            sorted = 1;
            while(index->Next != NULL)
            {
                if(*(index->Data) > *(index->Next->Data))
                {
                    Swap<T>(*(index->Data), *(index->Next->Data));
                    sorted = 0;
                }
                index=index->Next;
                iterations++;

            }
            current=current->Next;
        }

        cout << "Iterations: " << iterations << endl;
    }

    //Binary Search
    template<class T>
    static T BinarySearch(LinkedList<T> *list, T data)
    {
        Node<T> *minIndex = list->head;
        Node<T> *maxIndex = list->tail;
        Node<T> *midIndex = list->head;
        int flag=0;

        do
        {
            midIndex = GetMiddle<T>(minIndex,maxIndex);

            if(data == *(midIndex->Data))
            {
                flag=1;
                cout<<"found";
                return *(midIndex->Data);
            }
            else if(data > *(midIndex->Data))
            {
                minIndex = midIndex->Next;
            }
            else
            {
                maxIndex = midIndex->Prev;
            }

            }while(flag==0 && midIndex != minIndex);
            cout<<"not found";
            return -1;
        }
};

#endif // ALGORITHM_H
