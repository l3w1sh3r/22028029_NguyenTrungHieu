#include <iostream>

using namespace std;

struct List
{
    int count;
    int a[];

    int get(int index)
    {
        if (index < 0 || index >= count)
        {
            throw out_of_range("Index out of range");
        }
        return a[index];
    }; // O(1)
    void addFirst(int value)
    {
        for (int i = count; i > 0; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = value;
        count++;
    }; // O(N)
    void addLast(int value)
    {
        a[count] = value;
        count++;
    }; // O(1)
    void addAt(int index, int value)
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
    void removeFirst()
    {
        if (count == 0)
        {
            throw out_of_range("List is empty");
        }
        for (int i = 0; i < count - 1; i++)
        {
            a[i] = a[i + 1];
        }
        count--;
    }; // O(N)
    void removeLast()
    {
        if (count == 0)
        {
            throw out_of_range("List is empty");
        }
        count--;
    }; // O(1)
    void removeAt(int index)
    {
        if (index < 0 || index >= count)
        {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < count - 1; i++)
        {
            a[i] = a[i + 1];
        }
        count--;
    }; // O(N)
    void print()
    {
        for (int i = 0; i < count; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }; // O(N)
    void printReverse()
    {
        for (int i = count - 1; i >= 0; i--)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }; // O(N)
};