#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node()
	{
		data = 0;
		next = NULL;
	}

};

class Queue
{
public:
	Node* front;
	Node* rear;
	Queue()
	{
		front = rear = NULL;
	}

	bool isEmpty()
	{
		if (front == NULL )
			return true;
		else
			return false;

	}

	void Enqueue(int item)
	{
		Node* newnode = new Node();
		newnode->data = item;

		if (isEmpty())
			front = rear = newnode;
		else
		{
			rear->next = newnode;
			rear = newnode;
		}
	}


		int Dequeue()
	{
		int delvalue = -1;
		if (isEmpty())
			cout << "The queue is empty \n";
		else if (front == rear)
		{
			delete front;
			front = rear = NULL;
		}
		else
		{
			Node* delptr = front;
			front = front->next;
			delvalue = delptr->data;
			delete delptr;
		}

		return delvalue;
	}


	void display()
	{
		if (isEmpty())
			cout << "Queue is Empty, no items to display \n";
		else
		{
			Node* temp = front;
			while (temp != NULL)
			{
				cout << temp->data << "\t";
				temp = temp->next;
			}
			cout << endl;
		}
	}
};


int main()
{
	Queue q;
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.display();

	q.Dequeue();
	q.display();



}
