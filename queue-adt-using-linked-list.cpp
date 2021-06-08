#include "linkedlist.h"

template <class Item>
class Queue
{
private:
    LinkedList<int> list;

public:
    void enqueue(Item y); //insert int y to queue
    Item dequeue();       //delete the topmost item from queue
    void display();
};

template <class Item>
void Queue<Item>::enqueue(Item y)
{
    list.addTail(y);
}

template <class Item>
Item Queue<Item>::dequeue()
{
    int it;
    it = list.removeHead();
    return it;
}

template <class Item>
void Queue<Item>::display()
{
    list.display();
}

int main()
{
    int ch;
    int x;
    Queue<int> q;
    while (1)
    {
        cout << "\n1.Insert 2.Delete 3.Display 4.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the element: ";
            cin >> x;
            q.enqueue(x);
            break;

        case 2:
            cout << "Deleted -> " << q.dequeue() << "\n";
            break;
        case 3:
            q.display();
            cout << "\n";
            break;
        case 4:
            exit(0);
        }
    }
    return (0);
}