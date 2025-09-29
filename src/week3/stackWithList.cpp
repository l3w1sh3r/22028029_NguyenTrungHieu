#include <src/week3/stackWithList.h>
using namespace std;

Stack::Stack() {} // constructor

void Stack::push(int value)
{
    list.addLast(value);
} // them phan tu vao stack O(1)

int Stack::pop()
{
    if (isEmpty())
    {
        throw out_of_range("Stack is empty");
    }
    return list.removeLast();
} // lay phan tu ra khoi stack O(1)

int Stack::top()
{
    if (isEmpty())
    {
        throw out_of_range("Stack is empty");
    }
    return list.get(list.getSize() - 1);
} // lay phan tu tren cung cua stack O(1)

int Stack::bottom()
{
    if (isEmpty())
    {
        throw out_of_range("Stack is empty");
    }
    return list.get(0);
} // lay phan tu duoi cung cua stack O(1)

bool Stack::isEmpty()
{
    return list.isEmpty();
} // kiem tra stack co rong khong O(1)

int Stack::getSize()
{
    return list.getSize();
} // lay kich thuoc stack O(1)