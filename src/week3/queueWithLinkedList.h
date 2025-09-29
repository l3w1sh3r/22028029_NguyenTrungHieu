#ifndef QUEUEWITHLINKEDLIST_H
#define QUEUEWITHLINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include "src/week2/linkedList.h"

class Queue
{
private:
    LinkedList list; // su dung danh sach lien ket
public:
    Queue();              // constructor
    void push(int value); // them phan tu vao cuoi hang doi (EnQueue)
    int pop();            // lay phan tu dau tien ra khoi hang doi (DeQueue)
    int front();          // lay phan tu dau tien cua queue
    int back();           // lay phan tu cuoi cua queue
    bool isEmpty();       // kiem tra queue co rong khong
    int getSize();        // lay kich thuoc queue
};

#endif // QUEUEWITHLINKEDLIST_H