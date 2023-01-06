#include <iostream>

using namespace std;

template<class T>
class CircularQueue
{
private:
    T* arr;
    int front;
    int rear;
    int flag;
    int queueSize;
public:
    CircularQueue (int _queueSize)
    {
        front = rear = flag = 0;
        queueSize=_queueSize;
        arr=new T[queueSize];
    }
///to check if the queue is FULL
    int isFull()
    {
        if (rear==front && flag==1 )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
///to check if the queue is EMPTY
    int isEmpty()
    {
        if (front==rear && flag==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
///Add element to the queue
    void Enqueue(int value)
    {
        if (!isFull())
        {
            arr[rear]=value;
            if (rear<queueSize-1)
            {
                rear++;
            }
            else
            {
                rear=0;
                flag=1;
            }
        }
        else
        {
            cout<<"The Queue is Full!!!"<<endl;
        }
    }
///Remove element from the queue
    int Dequeue()
    {
        int retVal=-11111;
        if (!isEmpty())
        {
            retVal=arr[front];
            if (front<queueSize-1)
            {
                front++;
            }
            else
            {
                front=0;
            }
        }
        else
        {
            cout<<"Empty Queue"<<endl;
        }
        if (front==rear)
        {
            flag=0;
        }
        return retVal;
    }


    void Display()
    {
        if (front<rear)
        {
            for (int i=front; i<rear; i++) //not full
            {
                cout<<arr[i]<<" ";
            }
        }
        else if(rear==front && flag==1) //full queue
        {
            for (int i=0; i<queueSize; i++)
            {
                cout<<arr[i]<<" ";
            }
        }
        else if (front>rear) //after dequeuing
        {
            for (int i=front; i<queueSize; i++)
            {
                cout<<arr[i]<<" ";

            }
            for (int i=0; i<rear; i++)
            {
                cout<<arr[i]<<" ";

            }
        }
        cout<<endl;
    };

};

int main()
{
    CircularQueue<int> q1(6);
    q1.Enqueue(10);
    q1.Enqueue(20);
    q1.Enqueue(30);
    cout<<"Queue with space in the end: ";
    q1.Display();

    cout<<"Fully Queue: ";
    q1.Enqueue(40);
    q1.Enqueue(50);
    q1.Enqueue(60);
    q1.Display();
//try to enqueue to full queue
    q1.Enqueue(70);

    q1.Dequeue();
    q1.Dequeue();
    q1.Enqueue(70);
    cout<<"The Queue: ";
    q1.Display();



    return 0;
}
