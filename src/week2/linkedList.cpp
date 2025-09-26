#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {} // constructor
};
struct LinkedList
{
    Node *head;
    int size;

    LinkedList() : head(nullptr), size(0) {} // constructor

    // lay gia tri tai vi tri index O(n)
    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range");
        }
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    };

    // them dau O(1)
    void addFirst(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    };

    // them cuoi O(n)
    void addLast(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    };

    // them tai vi tri index O(n)
    void addAt(int index, int val)
    {
        if (index < 0 || index > size)
        {
            throw out_of_range("Index out of range");
        }
        if (index == 0)
        {
            addFirst(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    };

    // xoa dau O(1)
    void removeFirst()
    {
        if (!head)
        {
            throw out_of_range("List is empty");
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    };

    // xoa cuoi O(n)
    void removeLast()
    {
        if (!head)
        {
            throw out_of_range("List is empty");
        }
        if (!head->next)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next && current->next->next)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        size--;
    };

    // xoa tai vi tri index O(n)
    void removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range");
        }
        if (index == 0)
        {
            removeFirst();
            return;
        }
        Node *current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
        size--;
    };

    // in xuoi O(n)
    void print()
    {
        Node *current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    };

    // in nguoc O(n)
    void printReverse(Node *node)
    {
        if (!node)
            return;
        printReverse(node->next);
        cout << node->data << " ";
    };
    void printReverse()
    {
        printReverse(head);
        cout << endl;
    };
};