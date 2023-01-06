#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "node.h"
using namespace std;

template<class T>
class LinkedList
{
public:
    Node<T> *head, *tail;

    LinkedList()
    {
        head = tail = NULL;
        counter=0;
    }
//add function
    void Add(T &data)
    {
        Node<T> *node = new Node<T>(data);
        counter++;
//first node
        if(head == NULL)
        {
            head = tail = node;
        }
//other nodes
        else
        {
            tail->Next = node;
            node->Prev = tail;
            tail = node;
        }
    }

//display the linked list
    void Display()
    {
        Node<T> *current = head;

        while(current != NULL)
        {
            cout << *(current->Data) << "   ";
            current = current->Next;
        }
    }

//search for data
    int Search(T data)
    {
        Node<T> *node = GetNodeByData(data);

        if(node == NULL)
            return 0;
        else
            return 1;
    }

//remove data
    void Remove(int data)
    {
        Node<T> *node = GetNodeByData(data);

        if(node == NULL)
            return;
    //first node
        if(node == head)
        {
            //only one node in the linked list
            if(node == tail)
            {
                head = tail = NULL;
            }
            //there's other nodes
            else
            {
                head = head->Next;
                head->Prev = NULL;
            }
        }
     //last node
        else if(node == tail)
        {
            tail = tail->Prev;
            tail->Next = NULL;
        }
     //other nodes
        else
        {
            node->Prev->Next = node->Next;
            node->Next->Prev = node->Prev;
        }
        counter--;

        delete node;
    }

//counter for nodes(like indexes)
    int GetCount()
    {
        return counter;
    };


protected:

private:
    int counter;
//get node by data
    Node<T>* GetNodeByData(T data)
    {
        Node<T> *current = head;

        while(current != NULL)
        {
            if(&data == current->Data)
                return current;

            current = current->Next;
        }
//return null if not exist
        return NULL;
    }
};


#endif // LINKEDLIST_H
