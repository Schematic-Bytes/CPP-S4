#include "linkedlist.h"

template <class Item>
class Stack
{
private:
    LinkedList<int> list;

public:
    void push(Item y); //pushes int y to stack
    Item pop();        //pops out the topmost item from stack
    void Display();
};

template <class Item>
void Stack<Item>::push(Item y)
{
    list.addHead(y);
}

template <class Item>
Item Stack<Item>::pop()
{
    int it;
    it = list.removeHead();
    return it;
}

template <class Item>
void Stack<Item>::Display()
{
    list.display();
}

int main()
{
    int ch;
    int x;
    Stack<int> st;
    while (1)
    {
        cout << "1.Push 2.Pop 3.Display 4.Exit\n";
        cout << "Enter your choice: ";

        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the element: ";

            cin >> x;
            st.push(x);
            break;
        case 2:
            cout << "Deleted -> " << st.pop() << "\n";
            break;
        case 3:
            st.Display();
            cout << "\n";
            break;
        case 4:
            exit(0);
        }
    }
    return (0);
}