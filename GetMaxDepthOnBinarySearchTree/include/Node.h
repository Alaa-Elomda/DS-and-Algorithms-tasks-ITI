#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    public:

        T Data;
        Node *Left, *Right;

        Node(T data)
        {
            Data = data;
            Left = Right = NULL;
        }

    protected:

    private:
};

#endif // NODE_H
