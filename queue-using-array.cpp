//Queue using Array Program
#include <iostream>
#define MAX 10
#include <stdlib.h>

using namespace std;

class queue
{
    int queue1[MAX];
    int rear, front;

public:
    queue()
    {
        rear = front = -1;
    }
    int queuefull()
    {
        if (rear == MAX - 1)
        {
            cout << "queue full";
            return 0;
        }
        else
            return 1;
    }
    void insert(int x)
    {
        if (queuefull() == 1)
        {
            queue1[++rear] = x;
            cout << "inserted -> " << x;
        }
    }
    int queueempty()
    {
        if (front == rear)
        {
            cout << "queue empty";
            return 0;
        }
        else
            return 1;
    }
    void remove()
    {
        if (queueempty() == 1)
            cout << "deleted -> " << queue1[++front];
    }
    void display()
    {
        if (queueempty() == 1)
        {
            for (int i = front + 1; i <= rear; i++)
                cout << queue1[i] << " ";
        }
    }
};
int main()
{
    int ch;
    queue qu;
    while (1)
    {
        cout << "\n1.Insert 2.Delete 3.Display 4.Exit\n";
        cout << "Enter your choice > ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the element > ";
            cin >> ch;
            qu.insert(ch);
            break;
        case 2:
            qu.remove();
            break;
        case 3:
            qu.display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}