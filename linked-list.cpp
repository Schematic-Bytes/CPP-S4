#include <iostream>
#include <stdlib.h>
using namespace std;
template <class Item>
class LinkedList
{
private:
    class Node
    {
        friend class LinkedList;

    private:
        Item value;
        Node *next;

    public:
        Node(Item val, Node *nx = NULL)
        {
            value = val;
            next = nx;
        }
    } * m_head, *m_tail;
    int m_size;

public:
    LinkedList();                  //creates an empty list
    ~LinkedList();                 //destroys the list
    int size();                    //return number of nodes
    int isEmpty();                 //true if list is empty, false otherwise
    void addHead(Item item);       //add item to the front of the list
    Item removeHead();             //remove front node
    void addTail(Item item);       //add item to end of the list
    Item removeTail();             //remove last node
    void insert(int n, Item item); //Insert a new node at position n
    void display();
    Item remove(int n); //remove the node at position n
};
template <class Item>
LinkedList<Item>::LinkedList()
{
    m_head = NULL;
    m_tail = NULL;
    m_size = 0;
}
template <class Item>
LinkedList<Item>::~LinkedList()
{
    Node *here = m_head, *nextNode;
    while (here != NULL)
    {
        nextNode = here->next;
        delete here;
        here = nextNode;
    }
}
template <class Item>
int LinkedList<Item>::size()
{
    return m_size;
}
template <class Item>
int LinkedList<Item>::isEmpty()
{
    return (m_size);
}
template <class Item>
void LinkedList<Item>::addHead(Item item)
{
    m_head = new Node(item, m_head);
    if (m_tail == NULL)
        m_tail = m_head;
    m_size++;
}
template <class Item>
Item LinkedList<Item>::removeHead()
{
    Node *oldNode = m_head;
    Item returnVal = m_head->value;
    m_head = m_head->next;
    if (m_head == NULL)
        m_tail = NULL;
    m_size--;
    delete oldNode;
    return returnVal;
}
template <class Item>
void LinkedList<Item>::addTail(Item item)
{
    if (isEmpty())
        addHead(item);
    else
    {
        m_tail = m_tail->next = new Node(item);
        m_size++;
    }
}
template <class Item>
Item LinkedList<Item>::removeTail()
{
    if (m_head == m_tail)
        return removeHead();
    Node *preTail = m_head;
    Item returnVal = m_tail->value;
    while (preTail->next != m_tail)
        preTail = preTail->next;
    preTail->next = NULL;
    delete m_tail;
    m_tail = preTail;
    m_size--;
    return returnVal;
}
template <class Item>
void LinkedList<Item>::insert(int n, Item item)
{
    if (n == 1)
        addHead(item);
    else if (n == size() + 1)
        addTail(item);
    else
    {
        Node *here = m_head;
        for (int k = 1; k < n - 1; k++)
            here = here->next;
        here->next = new Node(item, here->next);
        m_size++;
    }
}
template <class Item>
Item LinkedList<Item>::remove(int n)
{
    if (n == 1)
        return removeHead();
    if (n == size())
        return removeTail();
    Node *here = m_head;
    for (int k = 1; k < n - 1; k++)
        here = here->next;
    Node *kill = here->next;
    Item returnVal = kill->value;
    here->next = kill->next;
    delete kill;
    m_size--;
    return returnVal;
}
template <class Item>
void LinkedList<Item>::display()
{
    if (isEmpty() == 0)
    {
        cout << "List is Empty";
    }
    else
    {
        Node *here = m_head;
        while (here != NULL)
        {
            cout << here->value;
            here = here->next;
        }
    }
}
int main()
{
    int ch;
    LinkedList<int> list;
    int item, pos;
    do
    {
        cout << "\n1.AddHead 2.AddTail 3.RemoveHead 4.RemoveTail ";
        cout << "5.Insert at middle 6.Delete From middle 7.Display 8.exit ";
        cout << "Enter your choice > ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the element > ";
            cin >> item;
            list.addHead(item);
            break;
        case 2:
            cout << "Enter the element > ";
            cin >> item;
            list.addTail(item);
            break;
        case 3:
            item = list.removeHead();
            cout << "Deleted: " << item;
            break;
        case 4:
            item = list.removeTail();
            cout << "Deleted: " << item;
            break;
        case 5:
            cout << "enter the element and position > ";
            cin >> item >> pos;
            list.insert(pos, item);
            break;
        case 6:
            cout << "enter the position > ";
            cin >> pos;
            item = list.remove(pos);
            cout << "Deleted: " << item;
            break;
        case 7:
            list.display();
            break;
        case 8:
            exit(0);
        }
    } while (ch != 8);
    return (0);
}