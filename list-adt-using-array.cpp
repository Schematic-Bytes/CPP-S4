#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class List
{
    int maxsize, size;
    T *lst;

public:
    List(int max);
    int isEmpty();
    void makeEmpty();
    void insert(int index, T item);
    void remove(int index);
    void getItem(int index);
    void display();
    void listSize();
};
template <class T>
List<T>::List(int max)
{
    maxsize = max;
    size = 0;
    lst = new T[maxsize];
}
template <class T>
void List<T>::makeEmpty()
{
    size = 0;
}
template <class T>
int List<T>::isEmpty()
{
    if (size == 0)
        return 1;
    else
        return 0;
}
template <class T>
void List<T>::insert(int index, T item)
{
    if (index <= size + 1)
    {
        for (int i = size; i >= index; i--)
            lst[i + 1] = lst[i];
        lst[index] = item;
        size = size + 1;
    }
    else
    {
        cout << "Cannot insert at this position";
        return;
    }
}
template <class T>
void List<T>::remove(int index)
{
    if (isEmpty())
    {
        cout << "List Empty";
        return;
    }
    if (index <= size)
    {
        for (int i = index; i < size; i++)
            lst[i] = lst[i + 1];
        size = size - 1;
    }
    else
    {
        cout << "Cannot remove from that position";
        return;
    }
}
template <class T>
void List<T>::display()
{
    if (isEmpty())
    {
        cout << "List Empty";
        return;
    }
    else
    {
        for (int i = 1; i <= size; i++)
            cout << lst[i] << endl;
    }
}
template <class T>
void List<T>::getItem(int index)
{
    if (index <= size)
    {
        cout << "Element: " << lst[index] << endl;
    }
    else
    {
        cout << "No element at that position";
        return;
    }
}
template <class T>
void List<T>::listSize()
{
    cout << "List SIze: " << size;
}
int main()
{
    int ch;
    int ele, pos;
    List<int> ls(1000);
    do
    {
        cout << "\n1.Insert 2.Delete 3.Display 4.GetItem 5.ListSize 6.MakeEmpty 7.Exit";
        cout << "\n Enter your choice > ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the element and position > ";
            cin >> ele >> pos;
            ls.insert(pos, ele);
            break;
        case 2:
            cout << "Enter position: ";
            cin >> pos;
            ls.remove(pos);
            break;
        case 3:
            ls.display();
            break;
        case 4:
            cout << "Enter Position: ";
            cin >> pos;
            ls.getItem(pos);
            break;
        case 5:
            ls.listSize();
            break;
        case 6:
            ls.makeEmpty();
            break;
        case 7:
            exit(0);
        }
    } while (ch != 7);
    return (0);
}