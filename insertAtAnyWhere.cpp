#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
    }
};

class LinkedList
{
private:
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    void insertAtFirst(int value)
    {
        Node *temp = new Node(value);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }

    void insertAtEnd(int value)
    {
        Node *temp = new Node(value);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void insertAtAnyWhere(int idx, int value)
    {
        Node *t = new Node(value);
        Node *temp = head;
        if (idx == size())
        {
            insertAtEnd(value);
        }
        else if (idx == 0)
        {
            insertAtFirst(value);
        }
        else if (idx < 0 || idx > size())
        {
            std::cout << "Wrong index" << std::endl;
            return;
        }
        for (int i = 1; i <= idx - 1; i++)
        {
            temp = temp->next;
        }
        t->next = temp->next;
        temp->next = t;
    }

    int getElement(int idx)
    {
        Node *temp = head;
        if (idx < 0 || idx >= size())
        {
            cout << "Wrong index" << std::endl;
            return -1;
        }
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    void deleteElement(int idx)
    {
        if (idx == 0)
        {
            head = head->next;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < idx - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
    }

    int size()
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << std::endl;
    }
};

int main()
{
    LinkedList ll;
    ll.insertAtFirst(1);
    ll.display();
    ll.insertAtFirst(2);
    ll.display();
    ll.insertAtEnd(4);
    ll.display();
    ll.insertAtEnd(5);
    ll.display();
    ll.insertAtAnyWhere(2, 10);
    ll.display();
    ll.deleteElement(0);
    ll.display();
    cout << ll.getElement(3) << std::endl;
    cout << "Size of the list is : " << ll.size() << std::endl;

    return 0;
}
