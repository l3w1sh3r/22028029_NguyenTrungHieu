#include "src/week2/linkedList.h"
using namespace std;

Node::Node(int val) : data(val), next(nullptr), prev(nullptr) {} // Node constructor

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {} // LinkedList constructor

// lay gia tri tai vi tri index O(n)
int LinkedList::get(int index)
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
void LinkedList::addFirst(int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        ;
    }
    size++;
};

// them cuoi O(1)
void LinkedList::addLast(int val)
{
    Node *newNode = new Node(val);
    /* without tail
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
    size++;*/

    // with tail
    if (!tail)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
};

// them tai vi tri index O(n)
void LinkedList::addAt(int index, int val)
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
    if (index == size - 1)
    {
        addLast(val);
        return;
    }
    Node *newNode = new Node(val);
    Node *current = head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    size++;
};

// xoa dau O(1)
int LinkedList::removeFirst()
{
    if (!head)
    {
        throw out_of_range("List is empty");
    }
    Node *temp = head;
    head = head->next;
    if (head)
    {
        head->prev = nullptr;
    }
    else
    {
        tail = nullptr; // List rong
    }
    size--;
    return temp->data;
};

// xoa cuoi O(1)
int LinkedList::removeLast()
{
    /* without tail
    if (!head)
    {
        throw out_of_range("List is empty");
    }
    if (!head->next)
    {

        head = nullptr;
        return head->data;
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
    size--;*/

    // with tail
    if (!tail)
    {
        throw out_of_range("List is empty");
    }
    Node *temp = tail;
    tail = tail->prev;
    if (tail)
    {
        tail->next = nullptr;
    }
    else
    {
        head = nullptr; // List rong
    }
    size--;
    return temp->data;
};

// xoa tai vi tri index O(n)
int LinkedList::removeAt(int index)
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
    if (index == size - 1)
    {
        removeLast();
        return;
    }
    Node *current = head;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = current->next->next;
    current->next->next->prev = current;
    size--;
    return temp->data;
};

// in xuoi O(n)
void LinkedList::print()
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
void LinkedList::printReverse()
{
    Node *current = tail;
    while (current)
    {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
};

// lay kich thuoc danh sach O(1)
int LinkedList::getSize()
{
    return size;
};

// kiem tra rong O(1)
bool LinkedList::isEmpty()
{
    return size == 0;
};