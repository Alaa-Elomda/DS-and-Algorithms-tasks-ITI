#include <iostream>

using namespace std;

//class node
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

//class stack
class Stack
{
	Node* top;

public:
	Stack()
	{
		top = NULL;
	}
	bool isEmpty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}
////Function Push
	void push(int item)
	{
		Node* newnode = new Node();
		newnode->data = item;
		if (isEmpty())
		{
			newnode->next = NULL;
			top = newnode;
		}
		else
		{
			newnode->next = top;
			top = newnode;
		}
	}
////Function Pop
	int pop()
	{
		int value;
		Node* delptr = top;
		value = top->data;
		top = top->next;
		delete delptr;
		return value;
	}
////Function Peek
	int Peek()
	{
		return top->data;
	}

////Function display
	void display()
	{
		Node* temp = top;
		while (temp != NULL)
		{
			cout <<"\n"<< temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

};


int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout<<"The stack values: ";
    s.display();
    cout << endl;
	s.pop();
	cout<<"The stack values: ";
    s.display();
    cout << endl;
	cout<<"The top value of the stack is: "<<s.Peek()<<endl;


}
