#include "src/week2/list.h"

using namespace std;
List::List() : count(0), capacity(4)
{
    a = new int[capacity];
} // constructor

void List::resize()
{
    capacity *= 2;
    int *newA = new int[capacity];
    for (int i = 0; i < count; i++)
    {
        newA[i] = a[i];
    }
    delete[] a;
    a = newA;
}; // O(N)

int List::get(int index)
{
    if (index < 0 || index >= count)
    {
        throw out_of_range("Index out of range");
    }
    return a[index];
}; // O(1)

void List::addFirst(int value)
{
    for (int i = count; i > 0; i--)
    {
        a[i] = a[i - 1];
    }
    a[0] = value;
    count++;
}; // O(N)

void List::addLast(int value)
{
    a[count] = value;
    count++;
}; // O(1)

void List::addAt(int index, int value)
{
    if (index < 0 || index > count)
    {
        throw out_of_range("Index out of range");
    }
    for (int i = count; i > index; i--)
    {
        a[i] = a[i - 1];
    }
    a[index] = value;
    count++;
}; // O(N)

int List::removeFirst()
{
    if (count == 0)
    {
        throw out_of_range("List is empty");
    }
    int first = a[0];
    for (int i = 0; i < count - 1; i++)
    {
        a[i] = a[i + 1];
    }
    count--;
    return first;
}; // O(N)

int List::removeLast()
{
    if (count == 0)
    {
        throw out_of_range("List is empty");
    }
    count--;
    return a[count];
}; // O(1)

int List::removeAt(int index)
{
    if (index < 0 || index >= count)
    {
        throw out_of_range("Index out of range");
    }
    int removed = a[index];
    for (int i = index; i < count - 1; i++)
    {
        a[i] = a[i + 1];
    }
    count--;
    return removed;
}; // O(N)

void List::print()
{
    for (int i = 0; i < count; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}; // O(N)

void List::printReverse()
{
    for (int i = count - 1; i >= 0; i--)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}; // O(N)

int List::getSize()
{
    return count;
}; // O(1)

bool List::isEmpty()
{
    return count == 0;
}; // O(1)
