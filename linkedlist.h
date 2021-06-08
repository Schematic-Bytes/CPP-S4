#include <iostream>
#include <stdlib.h>

using namespace std;

template <class Item>
class LinkedList
{
private:
    // sub-class Node
    class Node
    {
        friend class LinkedList;

    private:
        Item value;
        Node *next_node;

    public:
        Node(Item val, Node *nx = NULL)
        {
            value = val;
            next_node = nx;
        }
    } * head_node, *tail_node; // pointer pointing to the head node and tail node
    // total size of the linked list
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
// constructor
template <class Item>
LinkedList<Item>::LinkedList()
{
    head_node = NULL;
    tail_node = NULL;
    m_size = 0;
}
// deconstructor
template <class Item>
LinkedList<Item>::~LinkedList()
{
    Node *here = head_node, *nextNode;
    while (here != NULL)
    {
        nextNode = here->next_node;
        delete here;
        here = nextNode;
    }
}
// size method
template <class Item>
int LinkedList<Item>::size()
{
    return m_size;
}
// is empty method
template <class Item>
int LinkedList<Item>::isEmpty()
{
    return m_size;
}
// add head method
template <class Item>
void LinkedList<Item>::addHead(Item item)
{
    head_node = new Node(item, head_node);
    if (tail_node == NULL)
        tail_node = head_node;
    m_size++;
}
//
template <class Item>
Item LinkedList<Item>::removeHead()
{
    Node *oldNode = head_node;
    Item returnVal = head_node->value;
    head_node = head_node->next_node;
    if (head_node == NULL)
        tail_node = NULL;
    m_size--;
    delete oldNode;
    return returnVal;
}
template <class Item>
void LinkedList<Item>::addTail(Item item)
{
    if (isEmpty() == 0)
        addHead(item);
    else
    {
        tail_node = tail_node->next_node = new Node(item);
        m_size++;
    }
}
template <class Item>
Item LinkedList<Item>::removeTail()
{
    if (head_node == tail_node)
        return removeHead();
    Node *preTail = head_node;
    Item returnVal = tail_node->value;
    while (preTail->next_node != tail_node)
        preTail = preTail->next_node;
    preTail->next_node = NULL;
    delete tail_node;
    tail_node = preTail;
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
        Node *here = head_node;
        for (int k = 1; k < n - 1; k++)
            here = here->next_node;
        here->next_node = new Node(item, here->next_node);
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
    Node *here = head_node;
    for (int k = 1; k < n - 1; k++)
        here = here->next_node;
    Node *kill = here->next_node;
    Item returnVal = kill->value;
    here->next_node = kill->next_node;
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
        Node *here = head_node;
        while (here != NULL)
        {
            cout << here->value;
            here = here->next_node;
        }
    }
}