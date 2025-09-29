#ifndef STACKWITHLIST_H
#define STACKWITHLIST_H

#include <iostream>
#include <stdexcept>
#include <src/week2/list.h>

class Stack
{
private:
    List list; // su dung danh sach dong
public:
    Stack();              // constructor
    void push(int value); // them phan tu vao tren cung stack
    int pop();            // lay phan tu tren cung ra khoi stack
    int top();            // lay phan tu tren cung cua stack
    int bottom();         // lay phan tu duoi cung cua stack
    bool isEmpty();       // kiem tra stack co rong khong
    int getSize();        // lay kich thuoc stack
};

#endif // STACKWITHLIST_H