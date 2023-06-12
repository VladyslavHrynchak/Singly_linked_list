#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

template<class T>
class Singly_linked_list
{
    struct Node
    {
        Node *next = nullptr;
        T value;
    };

public:
    Singly_linked_list(){

    }

    Singly_linked_list(const Singly_linked_list &list)
    {
        Node *temp = list.head;
        while(temp)
        {
            push_back(temp->value);
            temp = temp->next;
        }
    }

    Singly_linked_list(Singly_linked_list &&list)
    {
        head = list.head;
        list.head = nullptr;
    }

    Singly_linked_list& operator =(const Singly_linked_list &list)
    {
        if(this != &list)
        {
            clear();

            Node *temp = list.head;
            while(temp)
            {
                push_back(temp->value);
                temp = temp->next;
            }

        }
        return *this;
    }

    Singly_linked_list& operator =(Singly_linked_list &&list)
    {
        if(this != &list)
        {
            clear();

            head = list.head;
            list.head = nullptr;
        }
        return *this;
    }

    ~Singly_linked_list()
    {
        clear();
    }

    void push_front(auto &&value_)
    {
        if(!head)
        {
            head = new Node();
            head->value = value_;
            head->next = nullptr;
        }
        else
        {
            Node *temp  = new Node;
            temp->value = value_;
            temp->next = head;
            head = temp;
        }
    }

    void print()
    {
        Node *temp = head;
        while(temp)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void clear()
    {
        if(head)
        {
            Node *temp = head;
            while(head)
            {
                temp = temp->next;
                delete head;
                head = temp;
            }
        }
    }

    T& front()
    {
        return head->value;
    }

    T* begin()
    {
        return &head->value;
    }

    T* end()
    {
        if(head)
        {
            Node *end = head;
            while(head)
            {
                end = head;
                head = head->next;
            }
            return &end->value;
        }
        return nullptr;
    }

    bool empty()
    {
        if(head)
            return false;

        return true;
    }

private:
    Node *head = nullptr;

};

#endif // SINGLY_LINKED_LIST_H
