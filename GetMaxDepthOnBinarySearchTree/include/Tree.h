#ifndef TREE_H
#define TREE_H

#include<iostream>
#include "Node.h"

using namespace std;

template<class T>
class Tree
{
    Node<T> *root;
public:
    Tree()
    {
        root = NULL;
    }

    void Add(T data)
    {
        Node<T> *node = new Node<T>(data);

        if(root == NULL)
        {
            root = node;
        }
        else
        {
            Node<T> *current = root;
            Node<T> *parent;

            while(current != NULL)
            {
                parent = current;

                if(data > current->Data)
                    current = current->Right;
                else
                    current = current->Left;
            }

            if(data > parent->Data)
                parent->Right = node;
            else
                parent->Left = node;
        }
    }

    void Remove(T data)
    {
        Node<T> *node = GetNodeByData(data);

        if(node == NULL)
            return;

        if(node == root)
        {
            if(root->Left == NULL && root->Right == NULL)
            {
                root = NULL;
            }
            else if(root->Right == NULL)
            {
                root = root->Left;
            }
            else if(root->Left == NULL)
            {
                root = root->Right;
            }
            else
            {
                Node<T> *newRoot = root->Left;
                Node<T> *maxRight = GetMaxRight(newRoot);

                maxRight->Right = root->Right;
                root = newRoot;
            }
        }
        else
        {
            Node<T> *parent = GetParent(node);
            Node<T> *newChild;

            if(node->Left == NULL && node->Right == NULL)
            {
                /*if(parent->Left == node)
                    parent->Left = NULL;
                else
                    parent->Right = NULL;*/

                newChild = NULL;
            }
            else if(node->Right == NULL)
            {
                /*if(parent->Left == node)
                    parent->Left = node->Left;
                else
                    parent->Right = node->Left;*/

                newChild = node->Left;

            }
            else if(node->Left == NULL)
            {
                /*if(parent->Left == node)
                    parent->Left = node->Right;
                else
                    parent->Right = node->Right;*/

                newChild = node->Right;
            }
            else
            {
                Node<T> *newParent = node->Left;
                Node<T> *maxRight = GetMaxRight(newParent);

                maxRight->Right = node->Right;

                /*if(parent->Left == node)
                    parent->Left = newParent;
                else
                    parent->Right = newParent;*/

                newChild = newParent;
            }

            if(parent->Left == node)
                parent->Left = newChild;
            else
                parent->Right = newChild;
        }

        delete node;
    }

    void Traverse()
    {
        Display(root);
    }
///////////////////assignment
    int GetMaxDepth()
    {
        int depth = Depth(root);
        return depth;
    }


protected:

private:

    int Depth(Node<T> *node)
    {
        if (node == NULL)
            return 0;
        else
        {
            int lDepth = Depth(node->Left);
            int rDepth = Depth(node->Right);

            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
    }

    void Display(Node<T> *node)
    {
        if(node == NULL)
            return;

        Display(node->Left);
        cout << node->Data << "   ";
        Display(node->Right);
    }

    Node<T>* GetNodeByData(T data)
    {
        Node<T> *current = root;

        while(current != NULL)
        {
            if(data == current->Data)
                return current;

            if(data > current->Data)
                current = current->Right;
            else
                current = current->Left;
        }

        return NULL;
    }

    Node<T>* GetParent(Node<T>* node)
    {
        Node<T> *parent = root;

        while(parent != NULL)
        {
            if(parent->Left == node || parent->Right == node)
                return parent;

            if(node->Data > parent->Data)
                parent = parent->Right;
            else
                parent = parent->Left;
        }

        return NULL;
    }

    Node<T>* GetMaxRight(Node<T> *node)
    {
        while(node->Right != NULL)
        {
            node = node->Right;
        }

        return node;
    }
};

#endif // TREE_H
