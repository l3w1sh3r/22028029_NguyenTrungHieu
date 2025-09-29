#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

class List
{
private:
    int count;
    int *a;
    int capacity;
    void resize(); // tang kich thuoc mang

public:
    List(); // constructor

    // lay gia tri tai vi tri index
    int get(int index);

    // them vao vi tri dau
    void addFirst(int value);

    // them vao vi tri cuoi
    void addLast(int value);

    // them vao vi tri index
    void addAt(int index, int value);

    // xoa phan tu dau
    int removeFirst();

    // xoa phan tu cuoi
    int removeLast();

    // xoa phan tu tai vi tri index
    int removeAt(int index);

    // lay kich thuoc danh sach
    int getSize();

    // in danh sach
    void print();

    // in nguoc
    void printReverse();

    // kiem tra rong
    bool isEmpty();
};

#endif // LIST_H