#ifndef STACKWITHLINKEDLIST_H
#define STACKWITHLINKEDLIST_H

#include <iostream>
#include <stdexcept>
#include "src/week2/linkedList.h"

class Stack
{
private:
    LinkedList list; // su dung danh sach lien ket
public:
    Stack();              // constructor
    void push(int value); // them phan tu vao tren cung stack
    int pop();            // lay phan tu tren cung ra khoi stack
    int top();            // lay phan tu tren cung cua stack
    int bottom();         // lay phan tu duoi cung cua stack
    bool isEmpty();       // kiem tra stack co rong khong
    int getSize();        // lay kich thuoc stack
};

#endif // STACKWITHLINKEDLIST_H