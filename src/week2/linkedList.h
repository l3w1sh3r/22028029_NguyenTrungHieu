#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val); // constructor
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList(); // constructor

    // lay gia tri tai vi tri index
    int get(int index);

    // them dau
    void addFirst(int val);

    // them cuoi
    void addLast(int val);

    // them tai vi tri index
    void addAt(int index, int val);

    // xoa dau
    int removeFirst();

    // xoa cuoi
    int removeLast();

    // xoa tai vi tri index
    int removeAt(int index);

    // lay kich thuoc danh sach
    int getSize();

    // in danh sach
    void print();

    // in nguoc danh sach
    void printReverse();

    // kiem tra rong
    bool isEmpty();
};

#endif // LINKEDLIST_H
