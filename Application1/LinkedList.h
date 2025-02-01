#pragma
#include <iostream>
#include "Node.h"

using namespace std;
template<class t>
class LinkedList
{
private:
    Node<t>* lift;
    Node<t>* right;
    int length;
public:
    LinkedList();
    Node<t>* begin();
    Node<t>* end();
    Node<t>* prevece(Node<t>* current);
    Node<t>* next(Node<t>* current);
    void insertLift(t element);
    void insertRight(t element);
    void insertAtPosition(int position, t element);
    void removeLift();
    void removeRight();
    void removeAtPosition(int position);
    int search(t element);
    void sortList();
    void print();
};

    template<class t>
    LinkedList<t>::LinkedList()
    {
        lift = right = NULL;
        length = 0;
    }

    template<class t>
    Node<t>* LinkedList<t>::begin()
    {
        return lift;
    }

    template<class t>
    Node<t>* LinkedList<t>::end()
    {
        return right;
    }

    template<class t>
    Node<t>* LinkedList<t>::prevece(Node<t>* current)
    {
        if (current != nullptr)
            return current->prevece;
        else
            return nullptr;
    }

    template<class t>
    Node<t>* LinkedList<t>::next(Node<t>* current)
    {
        if (current != nullptr)
            return current->next;
        else
            return nullptr;
    }

    template<class t>
    void LinkedList<t>::insertLift(t element)
    {
        Node<t>* newNode = new Node<t>;
        newNode->item = element;
        if (length == 0)
        {
            lift = right = newNode;
            newNode->next = newNode->prevece = NULL;
        }
        else
        {
            newNode->next = lift;
            newNode->prevece = NULL;
            lift->prevece = newNode;
            lift = newNode;
        }
        length++;
    }

    template<class t>
    void LinkedList<t>::insertRight(t element)
    {
        Node<t>* newNode = new Node<t>;
        newNode->item = element;
        if (length == 0)
        {
            lift = right = newNode;
            newNode->next = newNode->prevece = NULL;
        }
        else
        {
            newNode->next = NULL;
            newNode->prevece = right;
            right->next = newNode;
            right = newNode;
        }
        length++;
    }


    template<class t>
    void LinkedList<t>::insertAtPosition(int position, t element)
    {
        Node<t>* newNode = new Node<t>;
        newNode->item = element;
        if (position == 0)
        {
            insertLift(element);
        }
        else if (position == length)
        {
            insertRight(element);
        }
        else
        {
            Node<t>* current = lift;
            for (int i = 1; i < position; i++)
            {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prevece = current;
            current->next->prevece = newNode;
            current->next = newNode;
            length++;
        }

    }

    template<class t>
    void LinkedList<t>::removeLift()
    {
        if (length == 0)
        {
            cout << "Linked List is Empty can`t remove element" << endl;
        }
        else
        {
            Node<t>* current = lift;
            lift = lift->next;
            lift->prevece = NULL;
            current->next = current->prevece = NULL;
            delete current;
            length--;
        }
    }

    template<class t>
    void LinkedList<t>::removeRight()
    {
        if (length == 0)
        {
            cout << "Linked List is Empty can`t remove element" << endl;
        }
        else
        {
            Node<t>* current = right;
            right = right->prevece;
            right->next = NULL;
            current->next = current->prevece = NULL;
            delete current;
            length--;
        }
    }

    template<class t>
    void LinkedList<t>::removeAtPosition(int position)
    {
        if (position == 0)
        {
            removeLift();
        }
        else if (position == length - 1)
        {
            removeRight();
        }
        else
        {
            Node<t>* current = lift;
            for (int i = 0; i < position; i++)
            {
                current = current->next;
            }
            current->next->prevece = current->prevece;
            current->prevece->next = current->next;
            current->next = current->prevece = NULL;
            delete current;
            length--;
        }
    }

    template<class t>
    int LinkedList<t>::search(t element)
    {
        Node<t>* current = lift;
        for (int i = 0; i < length; i++)
        {
            if (current->item == element)
            {
                return i;
            }
            current = current->next;

        }
        return -1;
    }

    template<class t>
    void LinkedList<t>::sortList()
    {
        Node<t>* prevece = lift;
        Node<t>* current = NULL;
        while (prevece != NULL)
        {
            current = prevece->next;
            while (current != NULL)
            {
                if (prevece->item > current->item)
                {
                    swap(prevece->item, current->item);
                }
                current = current->next;
            }
            prevece = prevece->next;
        }

    }
  
    template<class t>
    void LinkedList<t>::print()
    {
        Node<t>* temp = lift;
        cout << "\n__________________________________________\n";
        while (temp != NULL)
        {
            cout << temp->item;
            temp = temp->next;
        }
        cout << "__________________________________________\n\n\n";
    }