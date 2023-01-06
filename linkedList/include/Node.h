#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    public:

        T Data;
        Node *Next, *Prev;

        Node(T data)
        {
            Data = data;
            Prev = Next = NULL;
        }

    protected:

    private:
};

#endif // NODE_H
