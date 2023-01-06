#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include<iostream>
#include <assert.h>

using namespace std;

template<class T>
class LinkedList
{
    Node<T> *head, *tail;

    public:
        LinkedList()
        {
            head = tail = NULL;
        }

        void Add(T data)
        {
            Node<T> *node = new Node<T>(data);

            if(head == NULL)
            {
                head = tail = node;
            }
            else
            {
                tail->Next = node;
                node->Prev = tail;
                tail = node;
            }
        }

        void Display()
        {
            Node<T> *current = head;

            while(current != NULL)
            {
                cout << current->Data << "   ";
                current = current->Next;
            }
        }

        int Search(T data)
        {
            Node<T> *node = GetNodeByData(data);

            if(node == NULL)
                return 0;
            else
                return 1;
        }

        void Remove(int data)
        {
            Node<T> *node = GetNodeByData(data);

            if(node == NULL)
                return;

            if(node == head)
            {
                if(node == tail)
                {
                    head = tail = NULL;
                }
                else
                {
                    head = head->Next;
                    head->Prev = NULL;
                }
            }
            else if(node == tail)
            {
                tail = tail->Prev;
                tail->Next = NULL;
            }
            else
            {
                /*Node *A = node->Prev;
                Node *B = node->Next;

                A->Next = B;
                B->Prev = A;*/

                node->Prev->Next = node->Next;
                node->Next->Prev = node->Prev;
            }

            delete node;
        }

////////////first function////////////////////////////////////////
        int GetCount()
        {
            int counter = 0;
            Node<T> *current = head;

            while(current != NULL)
            {
                counter ++;
                current = current->Next;
            }
            return counter;

        }

////////////Second function//////////////////////////////////////////
        T GetDataByIndex(int index)
        {
            Node<T> *current = head;
            int counter = 0;
            while(current != NULL)
            {
                if(counter == index)
                {
                    return (current->Data);
                }
                counter ++;
                current = current->Next;

            }
            assert(0 && "That isn't an index in the Linked List");
        }


////////////Third function//////////////////////////////////////////////////
        void InsertAfter(T data, T afterData)
        {
           Node<T> *node = new Node<T>(data);
           Node<T> *prevNode = GetNodeByData(afterData);
           if(prevNode != NULL)
           {
             node->Prev = prevNode;
             node->Next = prevNode->Next;
             prevNode->Next = node;
           }
           else
           {
              this->Add(data);
             /*tail->Next = node;
             node->Prev = tail;
             tail = node;*/
           }
        }

////////////Bonus/////////////////////////////////////////////////
////////////First Bonus///////////
        LinkedList<T>* Reverse()
        {
            LinkedList<T> *retVal = new LinkedList<T>();
            Node<T> *node = tail;
            while(node != NULL)
            {
                retVal->Add(node->Data);
                node=node->Prev;
            }
            return retVal;
        }

////////////Second Bonus///////////
        void InPlaceReverse()
        {
           Node<T> *current = head;
           Node<T> *prev = NULL;
           Node<T> *next = NULL;
           while(current != NULL)
           {
               next=current->Next;
               current->Next=prev;
               prev = current;
               current = next;
           }
           head = prev;
        }



/////////////////////////////////////////////////////////////////////////////////
    protected:

    private:

        Node<T>* GetNodeByData(T data)
        {
            Node<T> *current = head;

            while(current != NULL)
            {
                if(data == current->Data)
                    return current;

                current = current->Next;
            }

            return NULL;
        }
};

#endif // LINKEDLIST_H
