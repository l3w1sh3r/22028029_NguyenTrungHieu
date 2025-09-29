#include <src/week3/queueWithLinkedList.h>
using namespace std;

Queue::Queue() {} // constructor

void Queue::push(int value)
{
    list.addLast(value);
} // them phan tu vao cuoi hang doi O(1)

int Queue::pop()
{
    if (isEmpty())
    {
        throw out_of_range("Queue is empty");
    }
    return list.removeFirst();
} // lay phan tu dau tien ra khoi hang doi O(1)

int Queue::front()
{
    if (isEmpty())
    {
        throw out_of_range("Queue is empty");
    }
    return list.get(0);
} // lay phan tu dau tien cua queue O(1)

int Queue::back()
{
    if (isEmpty())
    {
        throw out_of_range("Queue is empty");
    }
    return list.get(list.getSize() - 1);
} // lay phan tu cuoi cua queue O(1)

bool Queue::isEmpty()
{
    return list.isEmpty();
} // kiem tra queue co rong khong O(1)

int Queue::getSize()
{
    return list.getSize();
} // lay kich thuoc queue O(1)