#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class cqueue
{
    T q[5], ele;
    int front, rear;

public:
    cqueue()
    {
        front = -1;
        rear = -1;
    }
    int cqfull()
    {
        if (front == (rear + 1) % 5)
        {
            cout << "Circular queue overflow";
            return 0;
        }
        else
            return 1;
    }
    void push()
    {
        if (cqfull() == 1)
        {
            cout << "Enter element";
            cin >> ele;
            if (front == -1 && rear == -1)
            {
                q[++rear] = ele;
                front = rear;
                return;
            }
            rear = (rear + 1) % 5;
            q[rear] = ele;
        }
    }
    int cqempty()
    {
        if (front == -1 && rear == -1)
        {
            cout << "underflow";
            return 0;
        }
        else
            return 1;
    }
    void pop()
    {
        if (cqempty() == 1)
        {
            cout << "Deleted" << q[front];
            if (front == rear)
            {
                front = rear = -1;
                return;
            }
            front = (front + 1) % 5;
        }
    }
    void display()
    {
        int i;
        if (cqempty() == 1)
        {
            if (front <= rear)
            {
                for (i = front; i <= rear; i++)
                    cout << q[i] << " ";
            }
            else
            {
                for (i = front; i <= 4; i++)
                {
                    cout << q[i] << " ";
                }

                for (i = 0; i <= rear; i++)
                {
                    cout << q[i] << " ";
                }
            }
        }
    }
};
main()
{
    int ch;
    cqueue<int> q1;
    while (1)
    {
        cout << "\n1.INSERT 2.DELETE 3.DISPLAY 4.EXIT\n";
        cout << "Enter your choice";
        cin >> ch;
        switch (ch)
        {
        case 1:
            q1.push();
            break;
        case 2:
            q1.pop();
            break;
        case 3:
            q1.display();
            break;
        case 4:
            exit(0);
        }
    }
}