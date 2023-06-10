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

    void push_front(const T value_)
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
            Node *deleted = head;
            while(head)
            {
                head = head->next;
                delete deleted;
                deleted = head;
            }
        }
    }

    void remove(const int index)
    {
        int iter = 0;
        Node *temp = head;
        Node *prev = head;
        while(temp)
        {
            if(iter == index)
            {
                if(iter == 0 && iter == index)
                    head = head->next;

                prev->next = temp->next;
                delete temp;
                temp = nullptr;

                return;
            }
            prev = temp;
            temp = temp->next;

            iter++;
        }
    }

private:
    Node *head = nullptr;

};

#endif // SINGLY_LINKED_LIST_H
